#include "config.h"

#include "auxtypes.h"

#include <QFile>
#include <QJsonDocument>


Config & Config::_()
{
    static Config configInstance {};

    return configInstance;
}

//----------------------------------------------------------------------
// Method: load
// load
//----------------------------------------------------------------------
bool Config::load(QString fileName)
{
    QFile loadFile(fileName);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open configuration file.");
        return false;
    }

    QByteArray readData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(readData));
    config = loadDoc.object();

    obtainCurrentHostIP();

    PATHBase    = general("workArea").toString();

    PATHProcs   = PATHBase + "/bin";
    PATHData    = PATHBase + "/data";
    PATHRun     = PATHBase + "/run";
    PATHWww     = PATHBase + "/www";    
    PATHBin     = PATHRun + "/bin";

    storage.inbox    = PATHData + "/inbox";
    storage.archive  = PATHData + "/archive";
    storage.gateway  = PATHData + "/gateway";
    storage.userArea = PATHData + "/user";

    storeAgentsAndHosts();

    return true;
}

//----------------------------------------------------------------------
// Method: obtainCurrentHostIP
// Obtain current host IP
//----------------------------------------------------------------------
void Config::obtainCurrentHostIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    for (int k = 0; k < list.count(); k++) {
        if (!list[k].isLoopback()) {
            if (list[k].protocol() == QAbstractSocket::IPv4Protocol) {
                QString ip = list[k].toString();
                if (ip.split(".").last() != "1") {
                    std::cerr << list[k].toString().toStdString() << "\n";
                    currentHostIP = ip;
                }
            }
        }
    }
    hostIsMaster = (currentHostIP == network()["masterNode"].toString());
}

//----------------------------------------------------------------------
// Method: storeAgentsAndHosts
// storeAgentsAndHosts
//----------------------------------------------------------------------
void Config::storeAgentsAndHosts()
{
    // Now processing host lines
    int j = 1;
    QJsonObject procNodes = network("processingNodes").toObject();
    for (auto & k : procNodes.keys()) {
        QString & pnName = k;
        int numOfTskAgents = procNodes[k].toInt();

        bool storeInMaps = (agentsInHost.find(pnName) == agentsInHost.end());

        QStringList agList;
        for (int i = 0; i < numOfTskAgents; ++i) {
            QString nn = QString("TskAgent_%1_%2")
                .arg(j,2,10,QLatin1Char('0'))
                .arg(i+1,2,10,QLatin1Char('0'));
            if (storeInMaps) {
                agList << nn;
                hostForAgent[nn] = pnName;
            }
        }
        if (storeInMaps) {
            agentsInHost[pnName] = agList;
        }
        ++j;
    }

}

//----------------------------------------------------------------------
// Method: str
// Returns the JSON content in form of string
//----------------------------------------------------------------------
QString Config::str()
{
    return QJsonDocument(config).toJson(QJsonDocument::Compact);
}
