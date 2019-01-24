#include "util.h"

#include <QJsonDocument>

#define T(a,b) { TASK_ ## a , #a }
std::map<TaskStatus, std::string> TaskStatusName = { TLIST_TASK_STATUS };
#undef T

#define T(a,b) { #a , TASK_ ## a }
std::map<std::string, TaskStatus> TaskStatusValue = { TLIST_TASK_STATUS };
#undef T

#define T(x) std::string( #x )
const std::string UserAreaName[] = { TLISTOF_USER_AREA_TYPES };
#undef T

const std::map<std::string, UserAreaId> UserAreaIdx = { {UserAreaName[UA_NOMINAL], UA_NOMINAL},
                                                        {UserAreaName[UA_LOCAL],   UA_LOCAL},
                                                        {UserAreaName[UA_VOSPACE], UA_VOSPACE} };

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

