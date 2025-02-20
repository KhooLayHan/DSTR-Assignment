// #pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

#include "Dataset.h"

#include "DateUtility.h"
#include "SimpleLogger.h"

namespace PerformanceEvaluation
{   
    bool Dataset::operator==(const Dataset& other) const {
        return 
            // id      == other.id         &&
            title   == other.title      &&
            text    == other.text       &&
            subject == other.subject    &&
            date    == other.date
        ;
    }

    bool Dataset::operator<(const Dataset& other) {
        return criteria(other);
    }
            
    bool Dataset::operator>(const Dataset& other) {
        return !criteria(other); // Descending order
    }

    void Dataset::display() {
        std::cout << "ID: " << id << "\n"
            << "Title: " << title << "\n"
            << "Text: " << text << "\n"
            << "Subject: " << subject << "\n"
            << "Date: " << date << "\n";
    }
            
    std::string Dataset::display() const {
        std::stringstream output_stream{};

        output_stream 
            << "ID: " << id << "\n"
            << "Title: " << title << "\n"
            << "Text: " << text << "\n"
            << "Subject: " << subject << "\n"
            << "Date: " << date 
        ;

        return output_stream.str();
    }

    // Primary criteria is to sort from year parsed from date, then secondary criteria is from subject 
    bool Dataset::criteria(const Dataset& other) {
        
        DateUtility date_utility{};

        int32_t year = date_utility.GetYear(date);
        int32_t other_year = date_utility.GetYear(other.date);
        
        if (year != other_year)
            return compareYearAscending(year, other_year);

        return compareSubjectAscending(subject, other.subject);
    }

    constexpr bool Dataset::compareTitleAscending(std::string_view first_title, std::string_view second_title) const {
        return first_title < second_title;
    }
            
    constexpr bool Dataset::compareTextAscending(std::string_view first_text, std::string_view second_text) const {
        return first_text < second_text;
    }

    constexpr bool Dataset::compareSubjectAscending(std::string_view first_subject, std::string_view second_subject) const {
        return first_subject < second_subject;
    }

    constexpr bool Dataset::compareDateAscending(std::string_view first_date, std::string_view second_date) const {
        return first_date < second_date;
    }

    constexpr bool Dataset::compareYearAscending(int32_t first_year, int32_t second_year) const {
        return first_year < second_year;
    }

    constexpr bool Dataset::compareMonthAscending(int32_t first_month, int32_t second_month) const {
        return first_month < second_month;
    }
            
    constexpr bool Dataset::compareDayAscending(int32_t first_day, int32_t second_day) const {
        return first_day < second_day;
    }
} // namespace PerformanceEvaluation
