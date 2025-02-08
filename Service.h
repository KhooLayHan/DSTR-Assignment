#pragma once

#include "SimpleLogger.h";

namespace PerformanceEvaluation {
    class Service {
        public:
            Service(SimpleLogger* logger) : m_Logger(logger) {}

            void UseLogger      (std::string_view, LogLevel, const Location& location = Location::current()) const;
            void UseDebugLogger (std::string_view, const Location& location = Location::current()) const;
            void UseInfoLogger  (std::string_view, const Location& location = Location::current()) const;
            void UseWarnLogger  (std::string_view, const Location& location = Location::current()) const;
            void UseErrorLogger (std::string_view, const Location& location = Location::current()) const;
            void UseFatalLogger (std::string_view, const Location& location = Location::current()) const;
        private:
            SimpleLogger* m_Logger;
    };
}