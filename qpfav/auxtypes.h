#ifndef AUXTYPES_H
#define AUXTYPES_H

#include "QsLogLevel.h"

namespace QPF {

#define O(s) QTextStream(stdout) << s << '\n';
#define E(s) QTextStream(stderr) << s << '\n';

enum LogLevel {
    TRACE = QsLogging::TraceLevel,
    DEBUG = QsLogging::DebugLevel,
    INFO  = QsLogging::InfoLevel,
    WARN  = QsLogging::WarnLevel,
    ERROR = QsLogging::ErrorLevel,
    FATAL = QsLogging::FatalLevel,
};

const QString LogLevelName[] = { "TRACE", "DEBUG", "INFO",
                                 "WARNING", "ERROR", "FATAL" };
}

#endif // AUXTYPES_H
