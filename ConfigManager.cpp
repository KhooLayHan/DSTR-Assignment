// #include "ConfigManager.h"
// namespace PerformanceEvaluation {
//     ConfigManager::ConfigManager() {
//         config["DEBUG"] = "0"; // Default: Debugging disabled
//         config["LOG_LEVEL"] = "2"; // Default: Set log level to 2
//         config["SOURCE_LOCATION_SUPPORTED"] = "1"; // Default: std::source_location is supported 
//         config["FILE_SIZE_LIMIT"] = "1048576"; // Default: 1MB in bytes
//         config["PLATFORM"] = DetectPlatform();

//         // Override with environment variables if they exist (only applicable in MacOS or Linux) 
//         if (const char* env_debug = std::getenv("DEBUG"))
//             config["DEBUG"] = env_debug;
//         if (const char* env_log_level = std::getenv("LOG_LEVEL"))
//             config["LOG_LEVEL"] = env_log_level;
//         if (const char* env_source_location_supported = std::getenv("SOURCE_LOCATION_SUPPORTED"))
//             config["SOURCE_LOCATION_SUPPORTED"] = env_source_location_supported;
//         if (const char* env_file_size_limit = std::getenv("FILE_SIZE_LIMIT"))
//             config["FILE_SIZE_LIMIT"] = env_file_size_limit;
//     };

//     // Parse command-line arguments of argv 
//     void ConfigManager::LoadFromArgs(int argc, char** argv) {
//         for (int i = 0; i != argc; i++) {
//             std::string arg = argv[i];

//             // Expect format: [--key=value]
//             if (arg.rfind("--", 0) == 0) { // Starts with "--"
//                 size_t position = arg.find('=');
                
//                 if (position != std::string::npos) {
//                     std::string key = arg.substr(2, position - 2);
//                     std::string value = arg.substr(position + 1);

//                     config[key] = value;
//                 }
//             }
//         }
//     };

//     std::string ConfigManager::Get(const std::string& key, const std::string& placeholder) const {        
//         auto it = config.find(key);
//         return it != config.end() ? it->second : placeholder;
//     };

//     int32_t ConfigManager::GetInt(const std::string& key, int32_t placeholder) const {
//         auto it = config.find(key);
//         return it != config.end() ? std::stoi(it->second) : placeholder;
//     };
    
//     bool ConfigManager::GetBool(const std::string& key, bool placeholder) const {
//         auto it = config.find(key);
//         return it != config.end() && (it->second == "1" || it->second == "true");
//     }

//     void ConfigManager::Set(const std::string& key, const std::string& value) {
//         config[key] = value;
//     };

//     constexpr std::string ConfigManager::DetectPlatform() {
//         #if defined(_WIN32)
//             return "Windows";
//         #elif defined(__linux__)
//             return "Linux";
//         #elif defined(__APPLE__)
//             return "MacOS";
//         #else   
//             return "Unknown";
//         #endif
//     }
// } // namespace PerformanceEvaluation
