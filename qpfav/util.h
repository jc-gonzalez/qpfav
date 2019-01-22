#ifndef UTIL_H
#define UTIL_H

#include <QJsonObject>
#include <QJsonArray>

#include <map>

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

extern std::map<TaskStatus, std::string> TaskStatusName;
extern std::map<std::string, TaskStatus> TaskStatusValue;

QJsonObject qStringToJObj(QString s);
QJsonObject stdStringToJObj(std::string s);

#endif // UTIL_H
