#pragma once

#include <regex>

#include "Array.h"
#include "WordList.h"
#include "WordListSorted.h"
#include "HashMap.h"
#include "LinkedList.h"
#include "Vector.h"
#include "HashSet.h"
#include "Dataset.h"

namespace PerformanceEvaluation
{
    HashMap<std::string, int32_t> GetWordCount(const WordList&);

    WordList ConvertLinkedListToWordList(const LinkedList&, HashSet<std::string>&);

    // WordList ConvertArrayToWordList(const Array<Dataset>&, WordList&);

    // Extract word-count pairs and sort them
    WordListSorted CheckAndSortHashMap(HashMap<std::string, int32_t>&);

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
} // namespace PerformanceEvaluation
