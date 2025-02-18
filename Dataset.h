#pragma once

#ifndef DATASET_HPP
#define DATASET_HPP

#include <string>
#include <string_view>

namespace PerformanceEvaluation
{   
    enum class Criteria {
        TEXT = 0,
        TITLE = 1,
        SUBJECT = 2,
        DATE = 3, // Publication year
    };

    class Dataset {
        public:
            int32_t m_Id;
            std::string m_Title;
            std::string m_Text;
            std::string m_Subject;
            std::string m_Date; 

            Dataset() {}

            Dataset(int32_t id) : m_Id(id) {}
            
            Dataset(int32_t id, std::string_view title, std::string_view text, std::string_view subject, std::string_view date) 
                : m_Id(id), m_Title(title), m_Text(text), m_Subject(subject), m_Date(date) {

            }

            // Dataset(const Dataset& dataset) {
                // SimpleLogger::Info("Dataset: Copy constructor was called.\n", LogHandler::CONSOLE);
            // }

            // Dataset(Dataset&& dataset) {
            //     SimpleLogger::Info("Dataset: Move constructor was called.\n", LogHandler::CONSOLE);
            // }
            
            // Dataset& operator =(const Dataset& dataset) {
            //     SimpleLogger::Info("Dataset: Copy assignment was called.\n", LogHandler::CONSOLE);
            // }
            
            // Dataset& operator =(Dataset&& dataset) {
            //     SimpleLogger::Info("Dataset: Move assignment was called.\n", LogHandler::CONSOLE);
            // }
    };
} // namespace PerformanceEvaluation

#endif