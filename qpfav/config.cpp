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

    storeAgentsAndHosts();

    return true;
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
        for (unsigned int i = 0; i < numOfTskAgents; ++i) {
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
