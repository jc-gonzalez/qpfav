#ifndef UTIL_H
#define UTIL_H

#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QMap>

//== Tasks

#define TLIST_TASK_STATUS                                       \
    T(SCHEDULED, -2),                                           \
    T(FAILED,    -1),                                           \
    T(FINISHED,   0),                                           \
    T(RUNNING,    1),                                           \
    T(PAUSED,     2),                                           \
    T(STOPPED,    3),                                           \
    T(ABORTED,    4),                                           \
    T(ARCHIVED,   5),                                           \
    T(UNKNOWN_STATE, 6)

#define T(a,b) TASK_ ## a = b
enum TaskStatus { TLIST_TASK_STATUS };
#undef T

extern QMap<TaskStatus, QString> TaskStatusName;
extern QMap<QString, TaskStatus> TaskStatusValue;

//== User Areas

#undef T

#define TLISTOF_USER_AREA_TYPES \
    T(NOMINAL),                              \
    T(LOCAL),                                \
    T(VOSPACE)

#define T(x) UA_ ## x
enum UserAreaId { TLISTOF_USER_AREA_TYPES };
#undef T

#define T(x) QString( #x )
extern const QString UserAreaName[];
#undef T

extern const QMap<QString, UserAreaId> UserAreaIdx;

//== Reprocessing flags and locations

enum Flags {
    NullFlags      = 0x00,
    GenIntermProd  = 0x01,
    OpenIPython    = 0x02,
    OpenJupyterLab = 0x04,
    OpenVOSpace    = 0x08,
};

enum OutputsLocation {
    LocalArch      = 0x100,
    LocalDir       = 0x200,
    VOSpaceFolder  = 0x400,
};

QJsonObject qStringToJObj(QString s);
QJsonObject stdStringToJObj(std::string s);

QString getFileContent(QFile * file);
QString getFileContent(QString fileName);

void binaryGetFITSHeader(QString fileName, QString & str);

#define showStatus(x) \
  mw->statusBar()->showMessage(x, 2000);

#endif // UTIL_H
