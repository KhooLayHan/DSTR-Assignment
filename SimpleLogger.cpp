// #pragma once

#include <iomanip>
#include <iostream>
#include <source_location>
#include <string>
#include <string_view>

#include "FileHandling.h"
#include "SimpleLogger.h"

namespace PerformanceEvaluation {
            
    SimpleLogger& SimpleLogger::getLogger() {
        static SimpleLogger logger;
        return logger;
    }
    
    void SimpleLogger::Log(std::string_view message, LogHandler handler, LogLevel level = LogLevel::DEBUG, const Location& location) {
        return getLogger().logImpl(message, handler, level, location);
    }
            
    void SimpleLogger::Debug(std::string_view message, LogHandler handler, const Location& location) {
        return getLogger().debugImpl(message, handler, location);
    }
            
    void SimpleLogger::Info(std::string_view message, LogHandler handler, const Location& location) {
        return getLogger().infoImpl(message, handler, location);
    }
            
    void SimpleLogger::Warn(std::string_view message, LogHandler handler, const Location& location) {
        return getLogger().warnImpl(message, handler, location);
    }
            
    void SimpleLogger::Error(std::string_view message, LogHandler handler, const Location& location) {
        return getLogger().errorImpl(message, handler, location);
    }
            
    void SimpleLogger::Fatal(std::string_view message, LogHandler handler, const Location& location) {
        return getLogger().fatalImpl(message, handler, location);
    }

    void SimpleLogger::logImpl(std::string_view message, LogHandler handler, LogLevel level, const Location& location) {
        setHandler(message, handler, level, location);
    }
            
    void SimpleLogger::debugImpl(std::string_view message, LogHandler handler, const Location& location) {
        setHandler(message, handler, LogLevel::DEBUG, location);
    }

    void SimpleLogger::infoImpl(std::string_view message, LogHandler handler, const Location& location) {
        setHandler(message, handler, LogLevel::INFO, location);
    }

    void SimpleLogger::warnImpl(std::string_view message, LogHandler handler, const Location& location) {
        setHandler(message, handler, LogLevel::WARN, location);
    }

    void SimpleLogger::errorImpl(std::string_view message, LogHandler handler, const Location& location) {
        setHandler(message, handler, LogLevel::ERROR, location);
    }

    void SimpleLogger::fatalImpl(std::string_view message, LogHandler handler, const Location& location) {
        setHandler(message, handler, LogLevel::FATAL, location);
    }

    void SimpleLogger::setHandler(std::string_view message, LogHandler handler, LogLevel level, const Location& location) {
        switch (handler) {
            case LogHandler::FILE:
                fileHandler(message, level, location);
                break;
            case LogHandler::CONSOLE:
                consoleHandler(message, level, location);
                break;
        }
    }

    void SimpleLogger::fileHandler(std::string_view message, const char* file, int32_t line, LogLevel level) {
        std::stringstream output_stream;

        output_stream 
            << "[" 
            << __DATE__ << "|"
            << __TIME__ << "|"
            << file << "|" // __FILE__
            << "Line " << line << "|" // __LINE__
            // * Note: __FUNCTION__ is not standard C++ 
            // * Note: __COLUMN__ predefined macro does not exist 
            << "]\n"
            << setLogLevel(level) << ": " << message 
            << "\n\n"
        ;

        FileHandling::appendFile("./Logs/log.txt", output_stream.str());
    }

    void SimpleLogger::consoleHandler(std::string_view message, const char* file, int32_t line, LogLevel level) {
        static int32_t id;

        std::cerr 
            << std::setw(3) << ++id << " [" 
            << __DATE__ << "|"
            << __TIME__ << "|"
            << file << "|" // __FILE__
            << "Line " << line << "|" // __LINE__
            // * Note: __FUNCTION__ is not standard C++ 
            // * Note: __COLUMN__ predefined macro does not exist 
            << "]\n" 
            << setLogLevel(level) << ": " << message
            << "\n"
        ;
    }

    void SimpleLogger::SimpleLogger::fileHandler(std::string_view message, LogLevel level, const Location& location) {
        std::stringstream output_stream;

        output_stream 
            << "[" 
            << __DATE__ << "|"
            << __TIME__ << "|"
            << location.file_name() << "|" 
            << "Line " << location.line() << "|"
            << location.function_name() << "|"
            << "Column " << location.column() 
            << "]\n"
            << setLogLevel(level) << ": " << message 
            << "\n\n"
        ;

        // FileHandling file;
        // file.appendFile("./Logs/log.txt", output_stream.str());
        FileHandling::appendFile("./Logs/log.txt", output_stream.str());
    
        // std::string file_path = "./Logs/log.txt"; 

        // std::ofstream file(file_path, std::ios::app);
        
        // if (!file) { 
        //     SimpleLogger::Warn("WriteFile Error: FILE " + file_path + "is not found.", LogHandler::FILE);
        //     return; 
        // }
        
        // file << output_stream.str();                
        // file.close();

        // Info("Successfully appended to file " + file_path, LogHandler::FILE);
    }

    void SimpleLogger::consoleHandler(std::string_view message, LogLevel level, const Location& location) {
        static int32_t id;

        std::cerr 
            << std::setw(3) << ++id << " [" 
            << __DATE__ << "|"
            << __TIME__ << "|"
            << location.file_name() << "|" 
            << "Line " << location.line() << "|"
            << location.function_name() << "|"
            << "Column " << location.column() 
            << "]\n"
            << setLogLevel(level) << ": " << message 
            << "\n\n"
        ;
    }

    constexpr std::string_view SimpleLogger::setLogLevel(LogLevel log_level) {
        std::string_view level = {};
        
        switch (log_level) {
            case LogLevel::DEBUG:   return "DEBUG";
            case LogLevel::INFO:    return "INFO";
            case LogLevel::WARN:    return "WARN";
            case LogLevel::ERROR:   return "ERROR";
            case LogLevel::FATAL:   return "FATAL";
        }

        return level;
    }
    
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
}
