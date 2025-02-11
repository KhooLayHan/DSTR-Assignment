
#include <iostream>
#include <string>
#include <string_view>
#include <memory>

#include "LinkedList.h"

#include "Dataset.h"
#include "DateUtility.cpp"
#include "SimpleLogger.h"

#include "SimpleLoggingService.h"

namespace PerformanceEvaluation {
    
    void LinkedList::insertBegin(const Dataset& dataset) {
        LinkedListNode* node = new LinkedListNode(dataset);
        node->next = m_Head;
        m_Head = node;
        
        incrementLength();
    }
            
    void LinkedList::insertEnd(const Dataset& dataset) {
            LinkedListNode* node = new LinkedListNode(dataset);

            if (m_Head == nullptr) {
                m_Head = node;
                
                incrementLength();

            return;
        }

        LinkedListNode* temp = m_Head;
        
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = node;

        incrementLength();
    }

    void LinkedList::insertPosition(const Dataset& dataset, size_t position) {
        LinkedListNode* node = new LinkedListNode(dataset);

        if (position == 0) {
            insertBegin(dataset);
            return;
        }

        LinkedListNode* temp = m_Head;
        for (size_t i = 0; temp != nullptr && i < position - i; i++) 
            temp = temp->next;

        if (temp == nullptr) {
            
            // SimpleFileLogger file_logger;
            // SimpleLoggingService::
            // SimpleLogger::Fatal("Position is out of bounds.", LogHandler::FILE);
            
            delete node;
            node = nullptr;

            return;
        }

        node->next = temp->next;
        temp->next = node;

        incrementLength();
    }
        
    void LinkedList::displayAll() const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        while (temp != nullptr) {
            std::cout << "ID: "         << temp->data.id      << "\n";
            std::cout << "TITLE: "      << temp->data.title   << "\n";
            std::cout << "TEXT: "       << temp->data.text    << "\n";
            std::cout << "SUBJECT: "    << temp->data.subject << "\n";
            std::cout << "DATE: "       << temp->data.date    << "\n";
            
            std::cout << "\n-----------\n\n";
            temp = temp->next;
        } 

        std::cout << "\n";
    }
    
    void LinkedList::displayFirst(int32_t count) const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        int32_t line = 0;

        while (temp != nullptr && line != count) {
            std::cout << "\n\033[34;1mID:\033[0m "         << temp->data.id      << "\n";
            std::cout << "\033[34;1mTITLE:\033[0m "      << temp->data.title   << "\n";
            std::cout << "\033[34;1mTEXT:\033[0m "       << temp->data.text    << "\n";
            std::cout << "\033[34;1mSUBJECT:\033[0m "    << temp->data.subject << "\n";
            std::cout << "\033[34;1mDATE:\033[0m "       << temp->data.date    << "\n";
            
            std::cout << "\n-----------\n";
            temp = temp->next;

            line++;
        } 

        std::cout << "\n";
    }

    void LinkedList::displayTitle() const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        std::cout << "TITLE\n-----------\n";
        
        while (temp != nullptr) {
            // SimpleLogger::Info(temp->data.title, LogHandler::FILE);
            // std::cout << temp->data.title << "\n";
            temp = temp->next;
        } 
        
        std::cout << "\n";
    }

    void LinkedList::displayText() const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        std::cout << "TEXT\n-----------\n";

        while (temp != nullptr) {
            std::cout << temp->data.text << "\n";
            temp = temp->next;
        } 

        std::cout << "\n";
    }
        
    void LinkedList::displaySubject() const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;
        
        std::cout << "SUBJECT\n-----------\n";
        
        while (temp != nullptr) {
            std::cout << temp->data.subject << "\n";
            temp = temp->next;
        } 

        std::cout << "\n";
    }

    void LinkedList::displayDate() const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        std::cout << "DATE\n-----------\n";

        while (temp != nullptr) {
            
            // SimpleLogger::Info(temp->data.date, LogHandler::FILE);
        
            // std::cout << temp->data.date << "\n";
            temp = temp->next;
        } 

        std::cout << "\n";
    }

    void LinkedList::search(std::string_view target, Criteria criteria) {
        // static constexpr bool is_string_v = std::is_same_v<std::decay_t<T>, std::string>;
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        while (temp != nullptr) { 
            Dataset dataset = temp->data;
            
            switch (criteria) {
                case Criteria::TITLE:
                    displayAllAfterSearch(dataset, dataset.title, target);
                    break;
                case Criteria::TEXT:
                    displayAllAfterSearch(dataset, dataset.text, target);
                    break;
                case Criteria::SUBJECT:
                    displayAllAfterSearch(dataset, dataset.subject, target);
                    break;
                case Criteria::DATE:
                    displayAllAfterSearch(dataset, dataset.date, target);
                    break;
            }

            temp = temp->next;
        };
    }

    void LinkedList::displayAfterSearch(const std::string& source, std::string_view target) const {
        if (contains(source, target)) {}
            // SimpleLogger::Info("Found: " + source, LogHandler::FILE);
    }    

    void LinkedList::displayAllAfterSearch(const Dataset& dataset, const std::string& source, std::string_view target) const {
        if (contains(source, target)) {
            // SimpleLogger::Info(dataset.display(), LogHandler::FILE);
            dataset.display();
            // FileHandling::appendFile("./Logs/log_test.txt", source);  
        }    
    }    

    void LinkedList::displayLength(std::string_view file_path) const {
        std::cout << "The total number of articles from the " << file_path << " dataset is "
            << getLength() << ".\n";
    }

    void LinkedList::displayLengthTrueDataset() const {
        std::cout << "The total number of articles from the true.csv dataset is "
            << getLength() << ".\n";
    }

    void LinkedList::displayLengthFakeDataset() const {
        std::cout << "The total number of articles from the fake.csv dataset is "
            << getLength() << ".\n";
    }

    size_t LinkedList::getLength() const {
        // size_t _length = 0;
        // LinkedListNode* temp = m_Head;
        
        // while (temp) {
        //     _length++;
        //     temp = temp->next;
        // }
        
        return m_Length;
    }

    void LinkedList::mergeSort() {
        m_Head = mergeSort(m_Head);
    }

    void LinkedList::deleteNode(const Dataset& dataset) {
        if (m_Head == nullptr) {
            // SimpleLogger::Warn("List is empty.", LogHandler::FILE);
            return;
        }

        // Deleting m_Head node scenario
        if (m_Head->data == dataset) {
            LinkedListNode* temp = m_Head;
            m_Head = m_Head->next;
            
            delete temp;
            temp = nullptr;

            // assert(temp != nullptr && "Attempted to delete from a linked list.");

            decrementLength();

            return;
        }

        // Deleting middle or end node scenario
        LinkedListNode* temp = m_Head;
        
        while (temp->next != nullptr && !(temp->next->data == dataset)) {
            temp = temp->next;
        }

        if (temp->next == nullptr) { 
            // SimpleLogger::Warn("Value cannot be found in the list.", LogHandler::FILE);
            return;
        }

        // Node to be deleted
        LinkedListNode* node = temp->next;
        temp->next = temp->next->next;
        
        delete node;
        node = nullptr;

        decrementLength();
    }

    void LinkedList::deleteAll() {
        LinkedListNode* current = m_Head;

        while (current != nullptr) {
            LinkedListNode* temp = current;
            current = current->next;
            
            // SimpleLogger::Info("Node has been deleted." + temp->data.title, LogHandler::CONSOLE);
            delete temp;
            temp = nullptr;

            decrementLength();
        }

        m_Head = nullptr;
        // SimpleLogger::Info("All nodes has been deleted.", LogHandler::FILE);
    }

    LinkedListNode* LinkedList::getHead() const {
        return m_Head;
    }

    void LinkedList::setHead(LinkedListNode* new_head) {
        m_Head = new_head;
    }

    void LinkedList::decrementLength() {
        if (m_Length > 0)
            m_Length--;
    }

    void LinkedList::incrementLength() {
        m_Length++;
    }

    // std::string substring(const std::string& data, size_t index) {
    //     if (index != std::string::npos) 
    //         return data.substr(index);
        
    //     SimpleLogger::Warn("Target index was not found.", LogHandler::FILE);
    //     return "";
    // }

    // constexpr bool LinkedList::contains(const std::string& data, std::string_view target) const {
    //     return data.find(target) != std::string::npos;
    // }
    // bool LinkedList::contains(const std::string& data, std::string_view target) const {
    //     return data.find(target) != std::string::npos;
    // }

    // std::string substringByIndex(const Dataset& dataset, Criteria criteria, size_t& index) {
    //     auto [id, text, title, subject, date] = dataset; 
    //     std::string new_string;

    //     switch (criteria) {
    //         case Criteria::TEXT:
    //             new_string = substring(text, index);
    //             break;
    //         case Criteria::TITLE:
    //             new_string = substring(title, index);
    //             break;
    //         case Criteria::SUBJECT:
    //             new_string = substring(subject, index);
    //             break;
    //         case Criteria::DATE:
    //             new_string = substring(date, index);
    //             break;
    //     }

    //     return new_string;
    // } 

    // void split() {

    // }

    // size_t findTargetIndex(const Dataset& dataset, Criteria criteria, std::string_view target) {
    //     auto [id, text, title, subject, date] = dataset; 
    //     size_t index;

    //     switch (criteria) {
    //         case Criteria::TEXT:
    //             index = text.find(target); 
    //             break;
    //         case Criteria::TITLE:
    //             index = title.find(target); 
    //             break;
    //         case Criteria::SUBJECT:
    //             index = subject.find(target); 
    //             break;
    //         case Criteria::DATE:
    //             index = date.find(target); 
    //             break;
    //     }

    //     return index;
    // }

    void LinkedList::isHeadEmpty() const {
        if (m_Head == nullptr) {
            // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
            return;
        }
    }

    void LinkedList::isHeadOrNextEmpty() const {
        if (m_Head == nullptr || m_Head->next == nullptr) {
            // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
            return;
        }
    }

    // Helper function to split the linked list into two halves
    LinkedListNode* LinkedList::getMiddle(LinkedListNode* temp) {
        if (temp == nullptr) {
            // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
            return temp;
        }

        LinkedListNode* first_half = temp;
        LinkedListNode* second_half = temp->next;
        
        // Iterate until second_half reaches the end of node, by then first_half will be the middle node
        while (second_half && second_half->next) {
            first_half = first_half->next;
            second_half = second_half->next->next;
        }

        return first_half; // first_half is the middle node
    }

    // Helper function to merge two sorted linked lists 
    LinkedListNode* LinkedList::merge(LinkedListNode* left, LinkedListNode* right) {
        LinkedListNode* dummy = new LinkedListNode({}); // Dummy node to simplify the merge process
        LinkedListNode* tail = dummy;

        DateUtility date_utility{};
        int32_t left_year = date_utility.getYear(left->data.date);
        int32_t right_year = date_utility.getYear(right->data.date);
    
        while (left != nullptr && right != nullptr) {
            if (left_year <= right_year) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        // Attach the remaining elements
        if (left != nullptr) {
            tail->next = left;
        } else {
            tail->next = right;
        }

        LinkedListNode* merged_head = dummy->next;
        
        delete dummy;
        dummy = nullptr;
        
        return merged_head;
    }

    // Applies merge sort recursively 
    LinkedListNode* LinkedList::mergeSort(LinkedListNode* temp) {                
        // List is already sorted if list is empty
        if (temp == nullptr || temp->next == nullptr) {
            // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
            return temp;
        }

        // Get the middle of list
        LinkedListNode* middle = getMiddle(temp);
        LinkedListNode* second_half = middle->next;

        // Split the list into two halves
        middle->next = nullptr;

        // Recursive sort
        LinkedListNode* left = mergeSort(temp);
        LinkedListNode* right = mergeSort(second_half);

        // Merge the sorted halves
        return merge(left, right);
    }
} // namespace PerformanceEvaluation


        // void containAnd(Dataset Dataset, Criteria criteria, std::string_view target) {
        //     auto [text, title, subject, date] = Dataset; 
        //     std::string new_string;
            
        //     switch (criteria) {
        //         case Criteria::TEXT:
        //             break; 
        //         case Criteria::TITLE:
        //             break; 
        //         case Criteria::SUBJECT:
        //             break; 
        //         case Criteria::DATE:
        //             break; 
        //     }
            
            // std::size_t index = findTargetIndex(Dataset, criteria, target);
            
            // if (substringByIndex(Dataset, criteria, index) {
            // }
            
            // return (findTargetIndex(Dataset, criteria, index, target) != std::string::npos) ? 
            //     substringByIndex(Dataset, criteria, index) : "";
        // }
