#pragma once

#include <iostream>
#include <sstream>

namespace PerformanceEvaluation {

    // Helper struct for LinkedList and Dataset class to parse the date from dataset to day, month, and year 
    struct DateUtility {    

        DateUtility() {}

        DateUtility(int32_t day, int32_t month, int32_t year)   
            : m_Day(day), m_Month(month), m_Year(year) {

        }

        struct MonthMap {
            std::string name;
            int32_t number;
        };

        static DateUtility parseDate(const std::string& date_str) {   
            static const MonthMap month_map[] = {
                { "January",  1 }, { "February",  2 }, { "March",     3 }, 
                { "April",    4 }, { "May",       5 }, { "June",      6 }, 
                { "July",     7 }, { "August",    8 }, { "September", 9 }, 
                { "October", 10 }, { "November", 11 }, { "December", 12 }
            };

            std::istringstream input_stream(date_str);
            
            std::string day, month, year;
     
            // Read the three expected parts (month, day, year)
            if (!(input_stream >> month >> day >> year)) {
                // std::cerr << "Error: Unable to parse date: " << date_str << "\n";
                return {};
            }       

            // Remove comma from day, e.g. [day], => [day] 
            if (!day.empty() && day.back() == ',')
                day.pop_back(); 

            // if (month.empty() || day.empty() || year.empty()) {
            //     return {};
            // }

            auto getMonth = [&](std::string_view month) {
                for (const auto& m : month_map) {
                    if (m.name == month)
                        return m.number;
                }

                return -1;
            };
            
            int32_t month_num = getMonth(month);
            if (month_num == -1) {
                // std::cerr << "Error: Invalid month: " << month << "\n";
                return {};
            }

            // try {
            //     return { std::stoi(day), month_num, std::stoi(year) };
            // } catch (...) {
            //     std::cerr << "Error: Invalid date format: " << date_str << "\n";
            //     return {};
            // }

            // std::cout << day << " " << month << " " << year << "\n";

            return { std::stoi(day), month_num, std::stoi(year) };

            // DateUtility date;
            // date.month = month_map[month];
            // date.day = std::stoi(day);
            // date.year = std::stoi(year);

            // return date;
        }

        // constexpr int32_t getDay(const Date& date) const {
        //     return date.day;
        //     return parseDate(date).day;
        // }
        
        // constexpr int32_t getMonth(const Date& date) const {
        //     return date.month;
        // }
        
        // constexpr int32_t getYear(const Date& date) const {
        //     return date.year;
        // }

        int32_t getDay(const std::string& date) const {
            auto [day, month, year] = parseDate(date);
            return day;
        }
        
        int32_t getMonth(const std::string& date) const {
            auto [day, month, year] = parseDate(date);
            return year;
        }
        
        int32_t getYear(const std::string& date) const {
            auto [day, month, year] = parseDate(date);

            return year;
        }

        int32_t m_Day;
        int32_t m_Month;
        int32_t m_Year;
    };
}