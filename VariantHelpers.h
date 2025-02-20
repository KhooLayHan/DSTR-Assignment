#pragma once

#include <iostream>
#include <string>
#include <variant>

#include "Dataset.h"
#include "Visitor.h"

namespace PerformanceEvaluation
{
    // Have to admit that this is entirely generated

    // Overloaded helper for std::visit
    template <typename... Ts>
    struct Overloaded : Ts... { 
        using Ts::operator()...;
    };

    // Deduction guide
    template <typename... Ts>
    Overloaded(Ts...) -> Overloaded<Ts...>;
    
    using DataVariant = std::variant<Dataset, std::string>;

    inline void ApplyVisitor(DataVariant& data, Visitor& visitor) {
        std::visit(Overloaded {
            [&](const std::string& str) { visitor.Visit(str); },
            [&](const Dataset& dataset) { visitor.Visit(dataset); }
        }, data);
    }

    struct DisplayVisitor {
        void operator()(const std::string& str) const {
            std::cout << str << "\n";
        }

        void operator()(const Dataset& dataset) const {
            std::cout << "\n\033[34;1mID:\033[0m "       << dataset.m_Id      << "\n";
            std::cout << "\033[34;1mTITLE:\033[0m "      << dataset.m_Title   << "\n";
            std::cout << "\033[34;1mTEXT:\033[0m "       << dataset.m_Text    << "\n";
            std::cout << "\033[34;1mSUBJECT:\033[0m "    << dataset.m_Subject << "\n";
            std::cout << "\033[34;1mDATE:\033[0m "       << dataset.m_Date    << "\n";
            
            std::cout << "\n-----------\n";
          
        }

        // void operator()(const Dataset& dataset, int32_t count) const {

        // }
    };
} // namespace PerformanceEvaluation
