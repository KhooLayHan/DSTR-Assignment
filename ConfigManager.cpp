#pragma once

#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP

#include <string>
#include <string_view>

namespace PerformanceEvaluation {
    class ConfigManager {
        public:
            ConfigManager(int argc, char** argv);

            void LoadFromArgs(int argc, char** argv);

            std::string Get(std::string_view key, std::string_view placeholder) const;
            int GetInt(std::string_view key, std::string_view placeholder) const;
            bool GetBool(std::string_view key, std::string_view placeholder) const;

            void Set(std::string_view key, std::string_view placeholder);
    };
} // namespace PerformanceEvaluation

#endif 