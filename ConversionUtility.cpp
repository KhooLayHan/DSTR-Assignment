#include "ConversionUtility.h"

namespace PerformanceEvaluation
{
    HashMap<std::string, int32_t> GetWordCount(const WordList& word_linked_list) {
        HashMap<std::string, int> word_count;

        WordListNode* temp = word_linked_list.GetHead();

        int i = 0;

        while (temp) {
            std::string word = temp->m_Data;
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            
            if (word_count.Contains(word))
                word_count[word]++;
            else    
                word_count.Insert(word, 1);

            i++;
            std::cout << i << " " << word << ": " << word_count[word] << "\n";

            temp = temp->m_Next;
        }

        return word_count;
    };

    WordList ConvertLinkedListToWordList(const LinkedList& linked_list, HashSet<std::string>& stopwords) {
        LinkedListNode* temp = linked_list.GetHead();
        WordList word_list;

        int j = 0;

        while (temp && j != 1) {
            if (j == 1) 
                break;
            
            const Dataset& dataset = temp->m_Data;
            
            auto text_parser = [](const std::string& text) {
                Vector<std::string> words;
                std::regex word_pattern(R"(\b([A-Za-z0-9]+(?:-[A-Za-z0-9]+)*|(?:[A-Za-z]\.){2,})\b)");
                
                std::sregex_iterator it(text.begin(), text.end(), word_pattern);
                std::sregex_iterator end;

                while (it != end) {
                    words.EmplaceBack(it->str());
                    ++it;
                }

                return words;
            };

            Vector<std::string> words = text_parser(dataset.m_Title + " " + dataset.m_Text);

            for (size_t i = 0; i != words.GetLength(); i++) {
                if (!stopwords.Contains(words[i])) {
                    word_list.InsertEnd(words[i]);
                }
            }
        
            temp = temp->m_Next;
            j++;
        }

        return word_list;
    };

    WordList ConvertArrayToWordList(const Array<Dataset>& array, WordList& word_list) {
        // Array temp = linked_list.GetHead();
        // WordListNode* word_temp = word_list.GetHead();

        // while (temp) {
        //     const Dataset& dataset = temp->m_Data;
            
        //     word_list.InsertEnd(dataset.ReadAll());
        
        //     temp = temp->m_Next;
        // }

        return word_list; 
    };

    // Extract word-count pairs and sort them
    WordListSorted CheckAndSortHashMap(HashMap<std::string, int32_t>& word_count) {
        WordListSorted sorted_list;

        for (const auto& [key, value] : word_count) {
            sorted_list.InsertSorted(key, value);
        }

        return sorted_list;
    }
} // namespace PerformanceEvaluation


                // auto gg = [](HashMap<std::string, int32_t>& word_count) {
                //     Vector<KeyValue> sorted_word_counts(word_count.begin(), word_count.end());
                    
                //     // Vector<KeyValue> sorted_word_counts;

                //     for (const auto& it = word_count.begin(); it != word_count.end(); ++it) {

                //     }

                //     for (size_t i = 0; i != word_count.BucketCount(); i++) {
                //         auto& bucket = word_count.m_Buckets[i];
                //     }

                //     // Sort by descending frequency 
                //     std::sort(sorted_word_counts.begin(), sorted_word_counts.end(), [](const KeyValue& a, const KeyValue& b) {
                //         return a.m_Value > b.m_Value; 
                //     });

                //     return sorted_word_counts;
                // };

                // auto rrr = gg(word_map);