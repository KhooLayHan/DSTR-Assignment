
#include <iostream>
#include <string>
#include <string_view>
#include <memory>

#include "LinkedList.h"

#include "Dataset.h"
#include "DateUtility.h"
#include "SimpleLogger.h"

#include "SimpleConsoleLogger.h"
#include "SimpleFileLogger.h"
#include "SimpleLoggingService.h"

namespace PerformanceEvaluation {
    
    void LinkedList::insertBegin(const Dataset& dataset) {
        LinkedListNode* node = new LinkedListNode(dataset);
        node->m_Next = m_Head;
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
        
        while (temp->m_Next != nullptr) {
            temp = temp->m_Next;
        }

        temp->m_Next = node;

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
            temp = temp->m_Next;

        if (temp == nullptr) {

            SimpleConsoleLogger console;
            SimpleLoggingService::UseFatalLogger(console, "Position is out of bounds."); 
            
            delete node;
            node = nullptr;

            return;
        }

        node->m_Next = temp->m_Next;
        temp->m_Next = node;

        incrementLength();
    }
        
    void LinkedList::displayAll() const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        while (temp != nullptr) {
            std::cout << "ID: "         << temp->m_Data.m_Id      << "\n";
            std::cout << "TITLE: "      << temp->m_Data.m_Title   << "\n";
            std::cout << "TEXT: "       << temp->m_Data.m_Text    << "\n";
            std::cout << "SUBJECT: "    << temp->m_Data.m_Subject << "\n";
            std::cout << "DATE: "       << temp->m_Data.m_Date    << "\n";
            
            std::cout << "\n-----------\n\n";
            temp = temp->m_Next;
        } 

        std::cout << "\n";
    }
    
    void LinkedList::displayFirst(int32_t count) const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        int32_t line = 0;

        while (temp != nullptr && line != count) {
            std::cout << "\n\033[34;1mID:\033[0m "         << temp->m_Data.m_Id      << "\n";
            std::cout << "\033[34;1mTITLE:\033[0m "      << temp->m_Data.m_Title   << "\n";
            std::cout << "\033[34;1mTEXT:\033[0m "       << temp->m_Data.m_Text    << "\n";
            std::cout << "\033[34;1mSUBJECT:\033[0m "    << temp->m_Data.m_Subject << "\n";
            std::cout << "\033[34;1mDATE:\033[0m "       << temp->m_Data.m_Date    << "\n";
            
            std::cout << "\n-----------\n";
            temp = temp->m_Next;

            line++;
        } 

        std::cout << "\n";
    }

    void LinkedList::displayTitle() const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        std::cout << "TITLE\n-----------\n";
        
        while (temp != nullptr) {

            SimpleConsoleLogger console;
            SimpleLoggingService::UseInfoLogger(console, temp->m_Data.m_Title); 
            
            temp = temp->m_Next;
        } 
        
        std::cout << "\n";
    }

    void LinkedList::displayText() const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        std::cout << "TEXT\n-----------\n";

        while (temp != nullptr) {
            std::cout << temp->m_Data.m_Text << "\n";
            temp = temp->m_Next;
        } 

        std::cout << "\n";
    }
        
    void LinkedList::displaySubject() const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;
        
        std::cout << "SUBJECT\n-----------\n";
        
        while (temp != nullptr) {
            std::cout << temp->m_Data.m_Subject << "\n";
            temp = temp->m_Next;
        } 

        std::cout << "\n";
    }

    void LinkedList::displayDate() const {
        isHeadEmpty();

        LinkedListNode* temp = m_Head;

        std::cout << "DATE\n-----------\n";

        while (temp != nullptr) {
            SimpleConsoleLogger console;
            SimpleLoggingService::UseInfoLogger(console, temp->m_Data.m_Date);
        
            // std::cout << temp->data.date << "\n";
            temp = temp->m_Next;
        } 

        std::cout << "\n";
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
        size_t length = 0;
        LinkedListNode* temp = m_Head;
        
        while (temp) {
            length++;
            temp = temp->m_Next;
        }
        
        return length;
    }

    // void LinkedList::mergeSort() {
    //     m_Head = mergeSort(m_Head);
    // }

    void LinkedList::deleteNode(const Dataset& dataset) {
        if (m_Head == nullptr) {
            SimpleConsoleLogger console;
            SimpleLoggingService::UseWarnLogger(console, "List is empty.");
            return;
        }

        // Deleting m_Head node scenario
        if (m_Head->m_Data == dataset) {
            LinkedListNode* temp = m_Head;
            m_Head = m_Head->m_Next;
            
            delete temp;
            temp = nullptr;

            // assert(temp != nullptr && "Attempted to delete from a linked list.");

            decrementLength();

            return;
        }

        // Deleting middle or end node scenario
        LinkedListNode* temp = m_Head;
        
        while (temp->m_Next != nullptr && !(temp->m_Next->m_Data == dataset)) {
            temp = temp->m_Next;
        }

        if (temp->m_Next == nullptr) { 
            SimpleConsoleLogger console;
            SimpleLoggingService::UseWarnLogger(console, "Value cannot be found in the list.");
            return;
        }

        // Node to be deleted
        LinkedListNode* node = temp->m_Next;
        temp->m_Next = temp->m_Next->m_Next;
        
        delete node;
        node = nullptr;

        decrementLength();
    }

    void LinkedList::deleteAll() {
        LinkedListNode* current = m_Head;

        while (current != nullptr) {
            LinkedListNode* temp = current;
            current = current->m_Next;
            
            // SimpleLogger::Info("Node has been deleted." + temp->data.title, LogHandler::CONSOLE);
            delete temp;
            temp = nullptr;

            decrementLength();
        }

        m_Head = nullptr;
        SimpleConsoleLogger console;
        SimpleLoggingService::UseInfoLogger(console, "All nodes has been deleted.");
        
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

    constexpr bool LinkedList::contains(const std::string& data, std::string_view target) const {
        return data.find(target) != std::string::npos;
    }

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
            SimpleConsoleLogger console;
            SimpleLoggingService::UseWarnLogger(console, "The linked list is empty.");
            return;
        }
    }

    void LinkedList::isHeadOrNextEmpty() const {
        if (m_Head == nullptr || m_Head->m_Next == nullptr) {
            SimpleConsoleLogger console;
            SimpleLoggingService::UseWarnLogger(console, "The linked list is empty.");
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
        LinkedListNode* second_half = temp->m_Next;
        
        // Iterate until second_half reaches the end of node, by then first_half will be the middle node
        while (second_half && second_half->m_Next) {
            first_half = first_half->m_Next;
            second_half = second_half->m_Next->m_Next;
        }

        return first_half; // first_half is the middle node
    }

    // Helper function to merge two sorted linked lists 
    // LinkedListNode* LinkedList::merge(LinkedListNode* left, LinkedListNode* right) {
    //     LinkedListNode* dummy = new LinkedListNode({}); // Dummy node to simplify the merge process
    //     LinkedListNode* tail = dummy;

    //     DateUtility date_utility{};
    //     int32_t left_year = date_utility.getYear(left->m_Data.m_Date);
    //     int32_t right_year = date_utility.getYear(right->m_Data.m_Date);
    
    //     while (left != nullptr && right != nullptr) {
    //         if (left_year <= right_year) {
    //             tail->m_Next = left;
    //             left = left->m_Next;
    //         } else {
    //             tail->m_Next = right;
    //             right = right->m_Next;
    //         }

    //         tail = tail->m_Next;
    //     }

    //     // Attach the remaining elements
    //     if (left != nullptr) {
    //         tail->m_Next = left;
    //     } else {
    //         tail->m_Next = right;
    //     }

    //     LinkedListNode* merged_head = dummy->m_Next;
        
    //     delete dummy;
    //     dummy = nullptr;
        
    //     return merged_head;
    // }

    // Applies merge sort recursively 
    // LinkedListNode* LinkedList::mergeSort(LinkedListNode* temp) {                
    //     // List is already sorted if list is empty
    //     if (temp == nullptr || temp->m_Next == nullptr) {
    //         // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
    //         return temp;
    //     }

    //     // Get the middle of list
    //     LinkedListNode* middle = getMiddle(temp);
    //     LinkedListNode* second_half = middle->m_Next;

    //     // Split the list into two halves
    //     middle->m_Next = nullptr;

    //     // Recursive sort
    //     LinkedListNode* left = mergeSort(temp);
    //     LinkedListNode* right = mergeSort(second_half);

    //     // Merge the sorted halves
    //     return merge(left, right);
    // }
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
