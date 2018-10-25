#include "config.h"

#include "auxtypes.h"

#include <QFile>
#include <QJsonDocument>

Config & Config::_()
{
    static Config configInstance {};

    return configInstance;
}

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

    return true;
}

//----------------------------------------------------------------------
// Method: str
// Returns the JSON content in form of string
//----------------------------------------------------------------------
QString Config::str()
{
    return QJsonDocument(config).toJson(QJsonDocument::Compact);
}
