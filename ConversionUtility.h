#pragma once

#include "Array.h"
#include "Dataset.h"
#include "FileHandling.h"
#include "HashMap.h"
#include "HashSet.h"
#include "LinkedList.h"
#include "Vector.h"
#include "WordList.h"
#include "WordListSorted.h"

#include "DynamicArray.h"

namespace PerformanceEvaluation
{
    HashMap<std::string, int32_t> GetWordCount(const WordList&);
    
    HashMap<std::string, int32_t> GetWordCount(const DynamicArray<std::string>&);
 
    WordList ConvertLinkedListToWordList(const LinkedList&, HashSet<std::string>&);

    DynamicArray<std::string> ConvertDynamicArrayToWordArray(const DynamicArray<Dataset>&, HashSet<std::string>&);

    // Extract word-count pairs and sort them to sorted linked list
    WordListSorted CheckAndSortHashMapLinkedList(HashMap<std::string, int32_t>&);
    
    // Extract word-count pairs and sort them to sorted word array
    DynamicArray<std::string> CheckAndSortHashMapArray(HashMap<std::string, int32_t>&);

    struct KeyValue {
        std::string m_Key;
        int32_t m_Value;

        // Allow construction from a std::pair<std::string, int>
        KeyValue& operator=(const std::pair<std::string, int>& p) {
            m_Key = p.first;
            m_Value = p.second;
            return *this;
        }
    };

    // Miscellaneous Question 2 Extra Exclusive
    void Question_2_ExtraExclusive(const FilePath& file_path = "./CSV/fake.csv");

    constexpr double CalculatePercentage(size_t numerator, size_t denominator) {
        return static_cast<double>((numerator * 100) / denominator);
    };;

    void DisplayFirst(size_t, const DynamicArray<Dataset>&);
    void DisplayAll(const DynamicArray<std::string>&);

} // namespace PerformanceEvaluation
