#pragma once

#ifndef SIMPLELOGGER_H
#define SIMPLELOGGER_H

#include <source_location>
#include <string>
#include <string_view>

namespace PerformanceEvaluation {
    
    enum class LogHandler {
        FILE = 0,
        CONSOLE = 1,
    };

    enum class LogLevel {
        DEBUG = 0,
        INFO = 1,
        WARN = 2,
        ERROR = 3,
        FATAL = 4,
    };

    class SimpleLogger {
        using Location = std::source_location;
        
        public: 
            SimpleLogger(const SimpleLogger&) = delete;
            
            SimpleLogger& operator=(const SimpleLogger&) = delete; 
            
            // static void Log(std::string_view, const char* file, int32_t line, LogHandler, LogLevel log_level) {
            //     return getLogger().logImpl(message, file, line,, log_level);
            // }

            static void Log(std::string_view, LogHandler, LogLevel, const Location& location = Location::current());

            static void Debug(std::string_view, LogHandler, const Location& location = Location::current());

            static void Info(std::string_view, LogHandler, const Location& location = Location::current());

            static void Warn(std::string_view, LogHandler, const Location& location = Location::current());

            static void Error(std::string_view, LogHandler, const Location& location = Location::current());

            static void Fatal(std::string_view, LogHandler, const Location& location = Location::current());

        protected:
            static SimpleLogger& getLogger();
        private:
            // void logImpl(std::string_view, const char* file, int32_t line, LogHandler, LogLevel log_level) {                
            //     switch (log_level) {
            //         case LogLevel::DEBUG:
            //             debugImpl(message,, location);
            //             break;
            //         case LogLevel::INFO:
            //             infoImpl(message, handler);
            //             break;
            //         case LogLevel::WARN:
            //             warnImpl(message, handler);
            //             break;
            //         case LogLevel::ERROR:
            //             errorImpl(message, handler);
            //             break;
            //         case LogLevel::FATAL:
            //             fatalImpl(message, handler);
            //             break;
            //     }
            // }

            void logImpl(std::string_view, LogHandler, LogLevel, const Location&);

            void debugImpl(std::string_view, LogHandler, const Location&);

            void infoImpl(std::string_view, LogHandler, const Location&);

            void warnImpl(std::string_view, LogHandler, const Location&);

            void errorImpl(std::string_view, LogHandler, const Location&);

            void fatalImpl(std::string_view, LogHandler, const Location&);

            void setHandler(std::string_view, LogHandler, LogLevel, const Location&);

            void fileHandler(std::string_view, const char*, int32_t, LogLevel);

            void consoleHandler(std::string_view, const char*, int32_t, LogLevel);

            void fileHandler(std::string_view, LogLevel, const Location&);

            void consoleHandler(std::string_view, LogLevel, const Location&);
            
            constexpr std::string_view setLogLevel(LogLevel);
            
            // constexpr std::string_view setLogHandler(LogHandler handler) {
            //     std::string_view handler = {};
                
            //     switch (handler) {
            //         case LogHandler::FILE:      return "File";
            //         case LogHandler::CONSOLE:   return "Console"; 
            //     }

            //     return handler;
            // }

            // Converts to std::string if needed
            // std::string setLogLevel(LogLevel log_level) {
            //     return std::string(logLevel(log_level));             }   
            // }

            SimpleLogger() {}
    };
}

#endif 