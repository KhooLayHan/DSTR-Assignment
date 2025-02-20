#pragma once

#include <iostream>
#include <string>

#include "Dataset.h"

namespace PerformanceEvaluation
{
    class Visitor {
        public:
            virtual void Visit(const std::string& str) = 0;
            virtual void Visit(const Dataset& dataset) = 0;

            virtual ~Visitor() = default;
    };
} // namespace PerformanceEvaluation
