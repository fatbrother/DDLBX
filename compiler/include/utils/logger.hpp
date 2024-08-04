#pragma once

#include <iostream>

namespace ddlbx::utility {

enum LogLevel {
    INFO,
    DEBUG,
    ERROR
};

/**
 * @brief Class for logging messages.
 */
class Logger {
public:
    Logger() = delete;
    ~Logger() = delete;
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    static void setLogLevel(LogLevel level) {
        logLevel = level;
    }

    static void info(const std::string &message);

    static void debug(const std::string &message);

    static void error(const std::string &message);

private:
    static LogLevel logLevel;
};

} // namespace ddlbx::utility