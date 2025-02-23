#include "SearchLinearArray.h"
#include "SimpleConsoleLogger.h"
#include "SimpleLoggingService.h"

namespace PerformanceEvaluation
{
    Array<Dataset> SearchLinearArray::UseLinearSearchAndCopyAlgorithm1(std::string_view target, const Array<Dataset>& array, Criteria criteria, SearchType type)
    {
        Array<Dataset> result;
        
        for (const auto& dataset : array)
        {
            std::string dataset_value;
            switch (criteria) {
                case Criteria::TITLE: dataset_value = dataset.m_Title; break;
                case Criteria::TEXT: dataset_value = dataset.m_Text; break;
                case Criteria::SUBJECT: dataset_value = dataset.m_Subject; break;
                case Criteria::DATE: dataset_value = dataset.m_Date; break;
                default: dataset_value = ""; break;
            }

            if (Contains(target, dataset_value, type)) {
                result.InsertEnd(dataset);
            }
        }

        return result;
    }
}
