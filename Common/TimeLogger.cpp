#include "TimeLogger.h"

#include "Logger.h"

TimeLogger::TimeLogger(LogTypes logType, const QString& operationName)
    : logType_(logType), operationName_(operationName)
{
    performanceTimer_.start();
}

TimeLogger::~TimeLogger()
{
    LOG(logType_,
        operationName_ + " in " +
            QString::number(performanceTimer_.elapsed() * 1.0 / 1000) +
            " seconds.");
}
