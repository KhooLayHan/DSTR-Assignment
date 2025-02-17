#pragma once

#ifndef ALGORITHM_MANAGER_H
#define ALGORITHM_MANAGER_H

#include <iostream>

#include "Dataset.h"
#include "DateUtility.h"

namespace PerformanceEvaluation {
    class AlgorithmManager {
        public:
            constexpr bool CheckFirstCriteria(int32_t first_year, int32_t second_year) const {
                return first_year != second_year; 
            };

            constexpr bool CheckSecondCriteria(int32_t first_month, int32_t second_month) const {
                return first_month != second_month; 
            };
            
            constexpr bool CheckThirdCriteria(int32_t first_day, int32_t second_day) const {
                return first_day != second_day; 
            };

            constexpr bool CheckFourthCriteria(int32_t first_subject, int32_t second_subject) const {
                return first_subject != second_subject; 
            };

            constexpr bool CheckDatasetByCriteria(const Dataset& first_dataset, const Dataset& second_dataset) const {
                
                

                // if (CheckFirstCriteria(first_dataset.m_Date))
                return true;
                // return first_subject != second_subject; 
            };

            constexpr bool CheckDatasetByCriteria(const Dataset& first_dataset, const Dataset& second_dataset) const {
                return true;
                // return std::tie()

            };
    };
};

#endif