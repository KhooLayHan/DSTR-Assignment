#include "Service.h";

namespace PerformanceEvaluation {
    void Service::UseLogger(std::string_view message, LogLevel level, const Location& location) const {
        m_Logger->Log(message, level, location);
    }
    
    void Service::UseDebugLogger(std::string_view message, const Location& location) const {
        m_Logger->Log(message, LogLevel::DEBUG, location);
    }
    
    void Service::UseInfoLogger(std::string_view message, const Location& location) const {
        m_Logger->Log(message, LogLevel::INFO, location);
    }
    
    void Service::UseWarnLogger(std::string_view message, const Location& location) const {
        m_Logger->Log(message, LogLevel::WARN, location);
    }
    
    void Service::UseErrorLogger(std::string_view message, const Location& location) const {
        m_Logger->Log(message, LogLevel::ERROR, location);
    }

    void Service::UseFatalLogger(std::string_view message, const Location& location) const {
        m_Logger->Log(message, LogLevel::FATAL, location);
    }
}