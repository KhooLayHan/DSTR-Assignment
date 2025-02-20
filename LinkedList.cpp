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
    
    void LinkedList::InsertBegin(const Dataset& data) {
        LinkedListNode* node = new LinkedListNode(data);
        node->m_Next = m_Head;
        m_Head = node;
        
        IncrementLength();
    }
            
    void LinkedList::InsertEnd(const Dataset& data) {
        // LinkedListNode* node = new LinkedListNode(std::move(data));
        LinkedListNode* node = new LinkedListNode(data);

        if (m_Head == nullptr) {
            m_Head = node;
            
            IncrementLength();

            return;
        }

        LinkedListNode* temp = m_Head;
        
        while (temp->m_Next != nullptr) {
            temp = temp->m_Next;
        }

        temp->m_Next = node;

        IncrementLength();
    }

    void LinkedList::InsertPosition(const Dataset& data, size_t position) {
        LinkedListNode* node = new LinkedListNode(data);
        // LinkedListNode* node = new LinkedListNode(std::move(data));

        if (position == 0) {
            InsertBegin(std::move(data));
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

        IncrementLength();
    }
        
    void LinkedList::DisplayAll() const {
        IsHeadEmpty();

        LinkedListNode* temp = m_Head;

        while (temp != nullptr) {
            // std::visit(DisplayVisitor{}, temp->m_Data);
            temp = temp->m_Next;
        } 

        std::cout << "\n";
    }
    
    void LinkedList::DisplayFirst(int32_t count) const {
        IsHeadEmpty();

        LinkedListNode* temp = m_Head;

        int32_t line = 0;

        while (temp != nullptr && line != count) {
            // std::visit(DisplayVisitor{}, temp->m_Data);
            temp = temp->m_Next;

            line++;
        } 

        std::cout << "\n";
    }

    void LinkedList::DisplayTitle() const {
        IsHeadEmpty();

        LinkedListNode* temp = m_Head;

        std::cout << "TITLE\n-----------\n";
        
        while (temp != nullptr) {
            // SimpleLogger::Info(temp->m_Data.title, LogHandler::FILE);
            // std::cout << temp->m_Data.title << "\n";
            temp = temp->m_Next;
        } 
        
        std::cout << "\n";
    }

    void LinkedList::DisplayText() const {
        IsHeadEmpty();

        LinkedListNode* temp = m_Head;

        std::cout << "TEXT\n-----------\n";

        while (temp != nullptr) {
            std::cout << temp->m_Data.m_Text << "\n";
            temp = temp->m_Next;
        } 

        std::cout << "\n";
    }
        
    void LinkedList::DisplaySubject() const {
        IsHeadEmpty();

        LinkedListNode* temp = m_Head;
        
        std::cout << "SUBJECT\n-----------\n";
        
        while (temp != nullptr) {
            std::cout << temp->m_Data.m_Subject << "\n";
            temp = temp->m_Next;
        } 

        std::cout << "\n";
    }

    void LinkedList::DisplayDate() const {
        IsHeadEmpty();

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

    void LinkedList::DisplayLength(std::string_view file_path) const {
        std::cout << "The total number of articles from the " << file_path << " dataset is "
            << GetLength() << ".\n";
    }

    // void LinkedList::displayLengthTrueDataset() const {
    //     std::cout << "The total number of articles from the true.csv dataset is "
    //         << getLength() << ".\n";
    // }

    // void LinkedList::DisplayLengthFakeDataset() const {
    //     std::cout << "The total number of articles from the fake.csv dataset is "
    //         << getLength() << ".\n";
    // }

    size_t LinkedList::GetLength() const {
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

    void LinkedList::DeleteNode(const Dataset& dataset) {
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

            DecrementLength();

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

        DecrementLength();
    }

    void LinkedList::DeleteAll() {
        LinkedListNode* current = m_Head;

        while (current != nullptr) {
            LinkedListNode* temp = current;
            current = current->m_Next;
            
            // SimpleLogger::Info("Node has been deleted." + temp->m_Data.title, LogHandler::CONSOLE);
            delete temp;
            temp = nullptr;

            DecrementLength();
        }

        m_Head = nullptr;
        // SimpleLogger::Info("All nodes has been deleted.", LogHandler::FILE);
    }

    LinkedListNode* LinkedList::GetHead() const {
        return m_Head;
    }

    void LinkedList::SetHead(LinkedListNode* new_head) {
        m_Head = new_head;
    }

    void LinkedList::DecrementLength() {
        if (m_Length > 0)
            m_Length--;
    }

    void LinkedList::IncrementLength() {
        m_Length++;
    }

    bool LinkedList::Contains(const std::string& m_Data, std::string_view target) const {
        return m_Data.find(target) != std::string::npos;
    }

    void LinkedList::IsHeadEmpty() const {
        if (m_Head == nullptr) {
            // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
            return;
        }
    }

    void LinkedList::IsHeadOrNextEmpty() const {
        if (m_Head == nullptr || m_Head->m_Next == nullptr) {
            // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
            return;
        }
    }
} // namespace PerformanceEvaluation