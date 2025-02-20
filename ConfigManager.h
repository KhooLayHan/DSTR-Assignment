#pragma once

#include <string>
#include <unordered_map>

#include "HashMap.h"
namespace PerformanceEvaluation {    
    class ConfigManager {
        public:
            ConfigManager();

            void LoadFromArgs(int argc, char** argv);

            std::string Get     (const std::string& key, const std::string& placeholder = "") const;
            int32_t     GetInt  (const std::string& key, int32_t placeholder = 0) const;
            bool        GetBool (const std::string& key, bool placeholder = false) const;

            void        Set     (const std::string& key, const std::string& value);
        private:
            static constexpr std::string DetectPlatform();

            // TODO: Replace std::unordered_map with custom implementation
            HashMap<std::string, std::string> config;
    };
} // namespace PerformanceEvaluation