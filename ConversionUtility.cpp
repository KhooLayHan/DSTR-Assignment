#include "ConversionUtility.h"

#include "FileHandling.h"
#include "SearchLinearLinkedList.h"
#include "Algorithm.h"

#include <sstream>

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

            std::stringstream ss;
            ss << i << " " << word << ": " << word_count[word] << "\n";
           
            FileHandling::AppendFileNewline(ss.str());

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

    // Extract word-count pairs and sort them
    WordListSorted CheckAndSortHashMap(HashMap<std::string, int32_t>& word_count) {
        WordListSorted sorted_list;

        for (const auto& [key, value] : word_count) {
            sorted_list.InsertSorted(key, value);
        }

        return sorted_list;
    }

    void Question_2_ExtraExclusive(const FilePath& file_path) {        
        LinkedList linked_list_fake;

        FileHandling::ReadFile(file_path, linked_list_fake);

        auto search_interface = std::make_unique<SearchLinearLinkedList>();
        auto search_interface_2 = std::make_unique<SearchLinearLinkedList>();

        LinkedList linked_list_impartial_searched_2016 = Algorithm::LinearSearchAndCopy(linked_list_fake, search_interface.get(), "2016", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_and_partial_search_subject_politics
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016, search_interface.get(), "politics", Criteria::SUBJECT, SearchType::PARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_january 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface_2.get(), "jan", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_february 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "feb", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_march 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "mar", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_april 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "apr", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_may 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "may", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_june 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "jun", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_july 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "jul", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_august 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "aug", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_september 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "sep", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_october 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "oct", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_november 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "nov", Criteria::DATE, SearchType::IMPARTIAL);
        
        LinkedList linked_list_impartial_searched_2016_december 
            = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "dec", Criteria::DATE, SearchType::IMPARTIAL);

        size_t january      = linked_list_impartial_searched_2016_january.GetLength(); 
        size_t february     = linked_list_impartial_searched_2016_february.GetLength();
        size_t march        = linked_list_impartial_searched_2016_march.GetLength();
        size_t april        = linked_list_impartial_searched_2016_april.GetLength();
        size_t may          = linked_list_impartial_searched_2016_may.GetLength();
        size_t june         = linked_list_impartial_searched_2016_june.GetLength();
        size_t july         = linked_list_impartial_searched_2016_july.GetLength();
        size_t august       = linked_list_impartial_searched_2016_august.GetLength();
        size_t september    = linked_list_impartial_searched_2016_september.GetLength();
        size_t october      = linked_list_impartial_searched_2016_october.GetLength();
        size_t november     = linked_list_impartial_searched_2016_november.GetLength();
        size_t december     = linked_list_impartial_searched_2016_december.GetLength();
        
        size_t fake_2016    = linked_list_impartial_searched_2016_and_partial_search_subject_politics.GetLength(); 

        double jan_fake_2016 = CalculatePercentage(january, fake_2016); 
        double feb_fake_2016 = CalculatePercentage(february, fake_2016); 
        double mar_fake_2016 = CalculatePercentage(march, fake_2016); 
        double apr_fake_2016 = CalculatePercentage(april, fake_2016); 
        double may_fake_2016 = CalculatePercentage(may, fake_2016); 
        double jun_fake_2016 = CalculatePercentage(june, fake_2016); 
        double jul_fake_2016 = CalculatePercentage(july, fake_2016); 
        double aug_fake_2016 = CalculatePercentage(august, fake_2016); 
        double sep_fake_2016 = CalculatePercentage(september, fake_2016); 
        double oct_fake_2016 = CalculatePercentage(october, fake_2016); 
        double nov_fake_2016 = CalculatePercentage(november, fake_2016); 
        double dec_fake_2016 = CalculatePercentage(december, fake_2016); 

        std::cout << "Percentage of Fake Political News Articles in 2016\n\n"; 

        std::cout << "January   | " << jan_fake_2016 << "%\n";
        std::cout << "February  | " << feb_fake_2016 << "%\n";
        std::cout << "March     | " << mar_fake_2016 << "%\n";
        std::cout << "April     | " << apr_fake_2016 << "%\n";
        std::cout << "May       | " << may_fake_2016 << "%\n";
        std::cout << "June      | " << jun_fake_2016 << "%\n";
        std::cout << "July      | " << jul_fake_2016 << "%\n";
        std::cout << "August    | " << aug_fake_2016 << "%\n";
        std::cout << "September | " << sep_fake_2016 << "%\n";
        std::cout << "October   | " << oct_fake_2016 << "%\n";
        std::cout << "November  | " << nov_fake_2016 << "%\n";
        std::cout << "December  | " << dec_fake_2016 << "%\n";   
    }

    void DisplayFirst(size_t count, const DynamicArray<Dataset>& array) {
        if (array.GetLength() == 0) {
            std::cout << "The array is empty." << std::endl;
            return;
        }
    
        count = (count > array.GetLength()) ? array.GetLength() : count; // Ensure we don't exceed array size
    
        for (size_t i = 0; i < count; i++) {
            const Dataset& data = array[i];
            std::cout << "ID: " << data.m_Id << "\n"
                      << "Title: " << data.m_Title << "\n"
                      << "Text: " << data.m_Text << "\n"
                      << "Subject: " << data.m_Subject << "\n"
                      << "Date: " << data.m_Date << "\n"
                      << "-----------------------\n";
        }
    }
} // namespace PerformanceEvaluation