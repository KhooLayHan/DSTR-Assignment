#pragma once

#ifndef DATASET_H
#define DATASET_H

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
            int32_t id;
            std::string title;
            std::string text;
            std::string subject;
            std::string date; 

            Dataset() {}

            Dataset(int32_t id) : id(id) {}
            
            Dataset(int32_t id, std::string_view title, std::string_view text, std::string_view subject, std::string_view date) 
                : id(id), title(title), text(text), subject(subject), date(date) {

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

            bool operator==(const Dataset&) const;

            bool operator<(const Dataset&);
            
            bool operator>(const Dataset&);

            void display();
            
            std::string display() const;

        protected:

            // Primary criteria is to sort from year parsed from date, then secondary criteria is from subject 
            bool criteria(const Dataset&);

            constexpr bool compareTitleAscending(std::string_view, std::string_view) const;
            
            constexpr bool compareTextAscending(std::string_view, std::string_view) const;

            constexpr bool compareSubjectAscending(std::string_view, std::string_view) const;

            constexpr bool compareDateAscending(std::string_view, std::string_view) const;

            constexpr bool compareYearAscending(int32_t, int32_t) const;

            constexpr bool compareMonthAscending(int32_t, int32_t) const;
            
            constexpr bool compareDayAscending(int32_t, int32_t) const;

            template<typename T> 
            void swap(T value_1, T value_2) {
                T temp = std::move(value_1);
                value_1 = std::move(value_2);
                value_2 = std::move(temp);
            }

            template<typename T> 
            void swap(T value_1, T value_2, bool (*compareFunc)(const Dataset&, const Dataset&)) {
                if (compareFunc) {
                    T temp = std::move(value_1);
                    value_1 = std::move(value_2);
                    value_2 = std::move(temp);
                }
            }
    };
} // namespace PerformanceEvaluation

#endif

            // static Date parseDate(const std::string& date_str) {           
            //     std::unordered_map<std::string, int32_t> month_map = {
            //         { "January",  1 }, { "February",  2 }, { "March",     3 }, 
            //         { "April",    4 }, { "May",       5 }, { "June",      6 }, 
            //         { "July",     7 }, { "August",    8 }, { "September", 9 }, 
            //         { "October", 10 }, { "November", 11 }, { "December", 12 }
            //     };
                
            //     std::istringstream input_stream(date_str);
                
            //     std::string day, month, year;
            //     input_stream >> month >> day >> year;

            //     // Remove comma from day
            //     if (!day.empty() && day.back() == ',')
            //         day.pop_back(); 

            //     Date date;
            //     date.month = month_map[month];
            //     date.day = std::stoi(day);
            //     date.year = std::stoi(year);

            //     return date;
            // }

            // Primary criteria is to sort from date, then secondary criteria is from subject 
            // bool setCriteria(const Dataset& other) {
            //     if (date != other.date)
            //         return compareDateAscending(date, other.date);

            //     return compareSubjectAscending(subject, other.subject);
            // }

            // constexpr bool criteria(const Dataset& first_dataset, const Dataset& second_dataset) const {
            //     // Primary criteria is to sort from year parsed from date , then secondary criteria is from subject 
                
            //     if (first_dataset.date != second_dataset.date)
            //         return compareDate(first_dataset.date, second_dataset.date);

            //     return compareSubject(first_dataset.subject, second_dataset.subject);
            // }

            // Primary criteria is to sort from year parsed from date, then secondary criteria is from subject
            // constexpr bool setCriteria(const Dataset& other) const {
            //     auto [day, month, year] = parseDate(this->date); 
            //     auto [other_day, other_month, other_year] = parseDate(other.date);

            //     return year != other_year; 
            // }

