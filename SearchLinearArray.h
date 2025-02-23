#pragma once

#include "Search.h"

namespace PerformanceEvaluation
{   
    class SearchLinearArray : public Search<Array<Dataset>> {
        public:
            Array<Dataset> UseLinearSearchAndCopyAlgorithm1(std::string_view target, const Array<Dataset>& array, Criteria criteria, SearchType type) override;
    };
}; // namespace PerformanceEvaluation

