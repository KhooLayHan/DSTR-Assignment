#include <iostream>
#include <string>
#include <string_view>
#include <memory>

#include "DateUtility.h"
#include "SimpleLogger.h"

#include "SimpleConsoleLogger.h"
#include "SimpleFileLogger.h"
#include "SimpleLoggingService.h"

#include "LinkedList.h"

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
            
            // SimpleFileLogger file_logger;
            // SimpleLoggingService::
            // SimpleLogger::Fatal("Position is out of bounds.", LogHandler::FILE);
            
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
            std::cout << "\n\033[34;1mID:\033[0m "       << temp->m_Data.m_Id      << "\n";
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
            // SimpleLogger::Info(temp->m_Data.title, LogHandler::FILE);
            // std::cout << temp->m_Data.title << "\n";
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
            SimpleFileLogger file;
            SimpleLoggingService::UseInfoLogger(file, temp->m_Data.m_Date);
        
            // std::cout << temp->m_Data.m_Date << "\n";
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

    // void LinkedList::LinearSearch(const std::unique_ptr<Search<LinkedList, LinkedListNode*> >& search_interface, std::string_view target, Criteria criteria) {
    //     if (search_interface) {
    //         search_interface->UseLinearSearchAlgorithm(target, *this, criteria);
    //     }
    // }
    
    // void LinkedList::LinearSearchToCopy(std::string_view target, const std::unique_ptr<Search<LinkedList, LinkedListNode*> >& search_interface, Criteria criteria) {
    //     if (search_interface) {
    //         search_interface->UseLinearSearchAndCopyAlgorithm(target, *this, criteria);
    //     }
    // }
    
    // void LinkedList::LinearSearchToDisplay(std::string_view target, const std::unique_ptr<Search<LinkedList, LinkedListNode*> >& search_interface, Criteria criteria) {
    //     if (search_interface) {
    //         search_interface->UseLinearSearchAndDisplayAlgorithm(target, *this, criteria);
    //     }
    // }

    // void LinkedList::SortBy(const std::unique_ptr<Sort<LinkedList, LinkedListNode*>>& sort_interface) {
    //     if (sort_interface) {
    //         sort_interface->UseSortingAlgorithm(*this);
    //     }
    // }

    void LinkedList::deleteNode(const Dataset& dataset) {
        if (m_Head == nullptr) {
            // SimpleLogger::Warn("List is empty.", LogHandler::FILE);
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
            // SimpleLogger::Warn("Value cannot be found in the list.", LogHandler::FILE);
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
            
            // SimpleLogger::Info("Node has been deleted." + temp->m_Data.title, LogHandler::CONSOLE);
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

    bool LinkedList::contains(const std::string& m_Data, std::string_view target) const {
        return m_Data.find(target) != std::string::npos;
    }

    void LinkedList::isHeadEmpty() const {
        if (m_Head == nullptr) {
            // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
            return;
        }
    }

    void LinkedList::isHeadOrNextEmpty() const {
        if (m_Head == nullptr || m_Head->m_Next == nullptr) {
            // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
            return;
        }
    }
} // namespace PerformanceEvaluation