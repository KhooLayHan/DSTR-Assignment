#pragma once

#include "Visitor.h"

namespace PerformanceEvaluation
{
    class VisitorGetDate : public Visitor {
        public:
            // std::string Visit(const std::string& str) override {
            //     std::cout << "[String] " << str << '\n';
            // }
            
            // void Visit(const Dataset& dataset) override {
            //     std::cout << "[Dataset] Title: " << dataset.m_Title << " | Subject: " << dataset.m_Subject << '\n';
            // }
    };
} // namespace PerformanceEvaluation
