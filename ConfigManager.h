#pragma once

#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP

#include <string>
#include <string_view>

#include <unordered_map>



namespace PerformanceEvaluation {
    // struct HashMap
    
    class ConfigManager {
        public:
            ConfigManager(int argc, char** argv);

            void LoadFromArgs(int argc, char** argv);

            std::string Get     (std::string_view key, std::string_view placeholder) const;
            int         GetInt  (std::string_view key, std::string_view placeholder) const;
            bool        GetBool (std::string_view key, std::string_view placeholder) const;

            void Set(std::string_view key, std::string_view value);

        private:

    };
} // namespace PerformanceEvaluation

#endif 