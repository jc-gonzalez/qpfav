#include "util.h"

#include <QJsonDocument>
#include <QTextStream>
#include <QFileInfo>
#include <QDataStream>
#include <QRegExp>

#include <iostream>

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

QString getFileContent(QFile * file)
{
    QTextStream in(file);
    return in.readAll();
}

QString getFileContent(QString fileName)
{
    QFileInfo fs(fileName);
    QFile file(fs.absoluteFilePath());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Cannot open file: " << fileName.toStdString() << std::endl;
        return "";
    }
    return getFileContent(&file);
}

//----------------------------------------------------------------------
// METHOD: binaryGetFITSHeader
//----------------------------------------------------------------------
void binaryGetFITSHeader(QString fileName, QString & str)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);    // read the data serialized from the file
    const int BUF_LEN = 80;
    const int TAG_LEN = 8;
    char buffer[BUF_LEN];
    int bytes, tbytes = 0;
    str = "{ \"Header\": { ";
    bool inHdr = true;
    bool isStart = true;
    int numOfExtensions = 0;

    while (!file.atEnd()) {
        bytes = in.readRawData(buffer, BUF_LEN);
        if (bytes < 0) { break; }
        tbytes += bytes;
        QString tag = QString::fromLocal8Bit(buffer, TAG_LEN);
        if (tag == "END     ") {
            str += "}";
            inHdr = false;
        } else {
            QString content = QString::fromLocal8Bit(buffer + TAG_LEN, BUF_LEN - TAG_LEN);
            if (content.at(0) == '=') {
                content.remove(0, 1);
            } else {
                content = "\"" + content + "\"";
            }
            if (tag == "XTENSION") {
                inHdr = true;
                content.replace(QRegExp("[ ]*/ .*$"), "");
                str += QString((numOfExtensions < 1) ? ", \"Extensions\": [ " : ", ") +
                    " { \"" + tag + "\": " + content;
                numOfExtensions++;
            } else {
                if (inHdr) {
                    content.replace(" T ", " true ");
                    content.replace(" F ", " false ");
                    content.replace(QRegExp("[ ]*/ .*$"), "");
                    if (!isStart) { str += ", "; }
                    str += "\"" + tag + "\": " + content;
                }
            }
        }
        isStart = false;
    }
    file.close();

    str += (numOfExtensions > 0) ? "] }": "}";
    //str.replace("'", "\"");
    str.replace(QRegExp("[ ]+\""), "\"");
    str.replace(QRegExp("[ ]+'"), "'");

    QRegExp * rx = new QRegExp("(\"HISTORY\"):(\".*\"),(\"HISTORY\":)");
    rx->setMinimal(true);
    int pos = 0;
    while ((pos = rx->indexIn(str, pos)) != -1) {
        QString srx(rx->cap(1) + ":" + rx->cap(2) + ",");
        str.replace(rx->cap(0), srx);
    }
    delete rx;
    rx = new QRegExp("(\"HISTORY\"):(\".*\")[}]");
    rx->setMinimal(true);
    pos = 0;
    while ((pos = rx->indexIn(str, pos)) != -1) {
        QString srx(rx->cap(1) + ": [" + rx->cap(2) + "] }");
        str.replace(rx->cap(0), srx);
        pos += srx.length();
    }
    delete rx;

    str.replace(",\"\":\"\"", "");
    str.replace("\":'", "\":\"");
    str.replace(QRegExp("'[ ]*,"), "\",");
}
