// #include <iomanip>
// #include <iostream>
// #include <string>
// #include <string_view>

// // #include "FileHandling.cpp"

// // #include "SimpleLogger.h"
// // class FileHandling;

// namespace PerformanceEvaluation {

//     SimpleLogger& SimpleLogger::getLogger() {
//         static SimpleLogger logger;
//         return logger;
//     }

//     void SimpleLogger::Log(std::string_view message, const char* file, int32_t line, LogLevel log_level) {
//         return getLogger().logImpl(message, file, line, log_level);
//     }

//     void SimpleLogger::logImpl(std::string_view message, const char* file, int32_t line, LogLevel log_level) {
//         switch (log_level) {
//             case LogLevel::WARN:
//             case LogLevel::DEBUG:
//                 consoleHandler(message, file, line, log_level);
//                 break;
//             case LogLevel::INFO:
//             case LogLevel::ERROR:
//             case LogLevel::FATAL:
//                 fileHandler(message, log_level);
//                 break;
//             case LogLevel::TRACE: // * Probably will not do anything.
//                 std::cout << "SimpleLogger is using TRACE LogLevel. Returning nothing...\n";
//                 return; 
//         }
//     }

//     void SimpleLogger::fileHandler(std::string_view message, LogLevel log_level) {
//         // static int64_t id;
//         int64_t id = 0;

//         std::cout << 
//             std::setw(3) << std::to_string(id) << " [ " 
//             << __DATE__ << " | "
//             << __TIME__ << " | "
//             << std::setw(50) << __FILE__ << " | " 
//             << std::setw(5) << "Line " << __LINE__ 
//             << "] " << setLogLevel(log_level) << ": "
//             << message << "\n"
//         ;

//         // FileHandling::writeFile("./Logs/log.txt", message);
//     }

//     void SimpleLogger::consoleHandler(std::string_view message, const char* file, int32_t line, LogLevel log_level) {
//         static int64_t id;
        
//         std::cout << std::setw(3) << ++id << " [" 
//             << __DATE__ << "|"
//             << __TIME__ << "|"
//             // << std::setw(20) << __FILE__ << "|" 
//             << file << "|" 
//             << std::setw(5) << "Line " << line 
//             << "] " << setLogLevel(log_level) << ": "
//             << message << "\n"
//         ;
//     }

//     std::string SimpleLogger::setLogLevel(LogLevel log_level) {
//         std::string level;
        
//         switch (log_level) {
//             case LogLevel::TRACE:
//                 level = "Trace";
//                 break;
//             case LogLevel::DEBUG:
//                 level = "Debug";
//                 break;
//             case LogLevel::INFO:
//                 level = "Info";
//                 break;
//             case LogLevel::WARN:
//                 level = "Warn";
//                 break;
//             case LogLevel::ERROR:
//                 level = "Error";
//                 break;
//             case LogLevel::FATAL:
//                 level = "Fatal";
//                 break;
//         }

//         return level;
//     }
// }