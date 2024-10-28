#pragma once

#include <iostream>

namespace ddlbx::utility {

#define STRINGIZING(x) #x
#define STR(x) STRINGIZING(x)
#define FILE_LINE __FILE__ ":" STR(__LINE__)
#define LOG_INFO(message) Logger::info(message, FILE_LINE)
#define LOG_DEBUG(message) Logger::debug(message, FILE_LINE)
#define LOG_ERROR(message) Logger::error(message, FILE_LINE)

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

    static void info(const std::string &message, const std::string &location);

    static void debug(const std::string &message, const std::string &location);

    static void error(const std::string &message, const std::string &location);

private:
    static LogLevel logLevel;
};

} // namespace ddlbx::utility