#include "util.h"

#include <QJsonDocument>

#define T(a,b) { TASK_ ## a , #a }
std::map<TaskStatus, std::string> TaskStatusName = { TLIST_TASK_STATUS };
#undef T

#define T(a,b) { #a , TASK_ ## a }
std::map<std::string, TaskStatus> TaskStatusValue = { TLIST_TASK_STATUS };
#undef T

QJsonObject qStringToJObj(QString s) {
    QJsonDocument json_doc = QJsonDocument::fromJson(s.toLocal8Bit());
    if (json_doc.isNull()) { exit(2); }
    if(!json_doc.isObject()) { exit(3); }
    return json_doc.object();
}

QJsonObject stdStringToJObj(std::string s) {
    QJsonDocument json_doc = QJsonDocument::fromJson(QString::fromStdString(s).toLocal8Bit());
    if (json_doc.isNull()) { exit(2); }
    if(!json_doc.isObject()) { exit(3); }
    return json_doc.object();
}

