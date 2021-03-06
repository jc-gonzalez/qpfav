#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QJsonObject>
#include <QJsonArray>
#include <QMap>
#include <QHostAddress>
#include <QNetworkInterface>

#include <iostream>

#define Sec(g)         DefGrp(g) \
                       DefGrpArray(g) \
                       DefGrpSec(g)
                       
#define DefGrp(g)      QJsonObject g () { return config[ #g ].toObject(); }
#define DefGrpArray(g) QJsonArray g ## Array () { return config[ #g ].toArray(); }
#define DefGrpSec(g)   QJsonValue g ( QString s ) { return g().value( s ); }

class Config
{
public:
    static Config & _();

    Sec(general)
    Sec(network)
    Sec(db)
    Sec(connectivity)
    Sec(products)
    Sec(orchestration)
    Sec(userDefTools)
    Sec(flags)

    //----------------------------------------------------------------------
    // Method: load
    // Loads the data from the configuration file
    //----------------------------------------------------------------------
    bool load(QString fileName);

    //----------------------------------------------------------------------
    // Method: str
    // Returns the JSON content in form of string
    //----------------------------------------------------------------------
    QString str();

    //----------------------------------------------------------------------
    // Method: operator[]
    // Reference to internal section
    //----------------------------------------------------------------------
    const QJsonObject operator[](QString s) { return config[s].toObject(); }

    //----------------------------------------------------------------------
    // Method: data
    // Reference to internal data
    //----------------------------------------------------------------------
    QJsonObject & data() { return config; }
    
private:
    //----------------------------------------------------------------------
    // Constructor
    //----------------------------------------------------------------------
    Config() {}

    void obtainCurrentHostIP();
    void storeAgentsAndHosts();
    
private:
    QJsonObject config;

public:
    bool isActualFile;
    QString cfgFileName;

    struct {
        QString inbox;
        QString archive;
        QString gateway;
        QString userArea;
    } storage;

    QString DBHost;
    QString DBPort;
    QString DBName;
    QString DBUser;
    QString DBPwd;

    QString PATHBase;
    QString PATHData;
    QString PATHProcs;
    QString PATHRun;
    QString PATHBin;
    QString PATHSession;
    QString PATHLog;
    QString PATHRlog;
    QString PATHTmp;
    QString PATHTsk;
    QString PATHMsg;
    QString PATHWww;

    mode_t PATHMode;

    QMap<QString,QStringList> agentsInHost;
    QMap<QString,QString>     hostForAgent;

    bool hostIsMaster;
    QString currentHostIP;
};


namespace Configuration {
    static ::Config & cfg = ::Config::_();
}

#endif // CONFIGURATION_H
