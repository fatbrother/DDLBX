#include "utils/logger.hpp"

namespace ddlbx::utility {

LogLevel Logger::logLevel = LogLevel::INFO;

enum ColorCode {
    FG_RED      = 31,
    FG_YELLOW   = 33,
    FG_GREEN    = 32,
    FG_BLUE     = 34,
    FG_DEFAULT  = 39,
};

void Logger::info(const std::string &message, const std::string &loc) {
#ifdef DDLBX_DEBUG
    if (logLevel <= LogLevel::INFO) {
        std::cout << "\033[" << ColorCode::FG_GREEN << "m[INFO]\033[" << ColorCode::FG_DEFAULT << "m " << message << " (" << loc << ")" << std::endl;
    }
#endif
}

void Logger::debug(const std::string &message, const std::string &loc) {
#ifdef DDLBX_DEBUG
    if (logLevel <= LogLevel::DEBUG) {
        std::cout << "\033[" << ColorCode::FG_BLUE << "m[DEBUG]\033[" << ColorCode::FG_DEFAULT << "m " << message << " (" << loc << ")" << std::endl;
    }
#endif
}

void Logger::error(const std::string &message, const std::string &loc) {
    std::cerr << "\033[" << ColorCode::FG_RED << "m[ERROR]\033[" << ColorCode::FG_DEFAULT << "m " << message << " (" << loc << ")" << std::endl;
}

} // namespace ddlbx::utility