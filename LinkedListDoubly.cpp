
#include <iostream>
#include <string>
#include <string_view>
#include <memory>

#include "LinkedListDoubly.h"

#include "DateUtility.h"
#include "SimpleLogger.h"

#include "LinkedListDoubly.h"

namespace PerformanceEvaluation
{
    // Insert a new node at the beginning of the list
    void LinkedListDoubly::InsertBegin(const Dataset &dataset) {
        LinkedListDoublyNode *node = new LinkedListDoublyNode(dataset);
        node->m_Next = m_Head;

        if (m_Head != nullptr){
            m_Head->m_Prev = node;
        }

        m_Head = node;

        IncrementLength();
    }

    // Insert a new node at the end of the list
    void LinkedListDoubly::InsertEnd(const Dataset &dataset) {
        LinkedListDoublyNode *node = new LinkedListDoublyNode(dataset);

        if (m_Head == nullptr)
        {
            m_Head = node;
            IncrementLength();
            return;
        }

        LinkedListDoublyNode *temp = m_Head;

        // Traverse to the last node
        while (temp->m_Next != nullptr)
        {
            temp = temp->m_Next;
        }

        temp->m_Next = node;
        node->m_Prev = temp;

        IncrementLength();
    }

    // Insert a new node at a specific position
    void LinkedListDoubly::InsertPosition(const Dataset &dataset, size_t position) {
        LinkedListDoublyNode *node = new LinkedListDoublyNode(dataset);

        if (position == 0) {
            InsertBegin(dataset);
            return;
        }

        LinkedListDoublyNode *temp = m_Head;

        // Traverse to the desired position
        for (size_t i = 0; temp != nullptr && i < position - 1; i++)
            temp = temp->m_Next;

        // If position is out of bounds
        if (temp == nullptr) {
            delete node;
            return;
        }

        node->m_Next = temp->m_Next;
        node->m_Prev = temp;
        
        if (temp->m_Next != nullptr) {
            temp->m_Next->m_Prev = node;
        }

        temp->m_Next = node;

        IncrementLength();
    }

    // Display all nodes in the linked list
    void LinkedListDoubly::DisplayAll() const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;

        while (temp != nullptr) {
            std::cout << "ID: " << temp->m_Data.m_Id << "\n";
            std::cout << "TITLE: " << temp->m_Data.m_Title << "\n";
            std::cout << "TEXT: " << temp->m_Data.m_Text << "\n";
            std::cout << "SUBJECT: " << temp->m_Data.m_Subject << "\n";
            std::cout << "DATE: " << temp->m_Data.m_Date << "\n";
            std::cout << "\n-----------\n\n";

            temp = temp->m_Next;
        }

        std::cout << "\n";
    }

    // Display the first 'count' number of articles
    void LinkedListDoubly::DisplayFirst(int32_t count) const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
        int32_t line = 0;

        while (temp != nullptr && line != count) {
            std::cout << "\n\033[34;1mID:\033[0m " << temp->m_Data.m_Id << "\n";
            std::cout << "\033[34;1mTITLE:\033[0m " << temp->m_Data.m_Title << "\n";
            std::cout << "\033[34;1mTEXT:\033[0m " << temp->m_Data.m_Text << "\n";
            std::cout << "\033[34;1mSUBJECT:\033[0m " << temp->m_Data.m_Subject << "\n";
            std::cout << "\033[34;1mDATE:\033[0m " << temp->m_Data.m_Date << "\n";
            std::cout << "\n-----------\n";

            temp = temp->m_Next;
            line++;
        }

        std::cout << "\n";
    }

    // Display only the titles of all articles
    void LinkedListDoubly::DisplayTitle() const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
        std::cout << "TITLE\n-----------\n";

        while (temp != nullptr)
        {
            std::cout << temp->m_Data.m_Title << "\n";
            temp = temp->m_Next;
        }

        std::cout << "\n";
    }

    // Display only the text content of all articles
    void LinkedListDoubly::DisplayText() const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
        std::cout << "TEXT\n-----------\n";

        while (temp != nullptr)
        {
            std::cout << temp->m_Data.m_Text << "\n";
            temp = temp->m_Next;
        }

        std::cout << "\n";
    }

    // Display only the subjects of all articles
    void LinkedListDoubly::DisplaySubject() const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
        std::cout << "SUBJECT\n-----------\n";

        while (temp != nullptr)
        {
            std::cout << temp->m_Data.m_Subject << "\n";
            temp = temp->m_Next;
        }

        std::cout << "\n";
    }

    // Display only the publication dates of all articles
    void LinkedListDoubly::DisplayDate() const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
        std::cout << "DATE\n-----------\n";

        while (temp != nullptr)
        {
            std::cout << temp->m_Data.m_Date << "\n";
            temp = temp->m_Next;
        }

        std::cout << "\n";
    }

    // Get the total number of articles in the linked list
    size_t LinkedListDoubly::GetLength() const {
        size_t length = 0;
        LinkedListDoublyNode *temp = m_Head;

        while (temp)
        {
            length++;
            temp = temp->m_Next;
        }

        return length;
    }

    // Delete a specific node from the list
    void LinkedListDoubly::DeleteNode(const Dataset &dataset) {
        if (m_Head == nullptr)
            return;

        if (m_Head->m_Data == dataset) {
            LinkedListDoublyNode *temp = m_Head;
            m_Head = m_Head->m_Next;

            if (m_Head != nullptr)
            {
                m_Head->m_Prev = nullptr;
            }

            delete temp;
            DecrementLength();
            return;
        }

        LinkedListDoublyNode *temp = m_Head;
        while (temp->m_Next != nullptr && !(temp->m_Next->m_Data == dataset))
        {
            temp = temp->m_Next;
        }

        if (temp->m_Next == nullptr)
            return;

        LinkedListDoublyNode *node = temp->m_Next;
        temp->m_Next = temp->m_Next->m_Next;

        if (temp->m_Next != nullptr)
        {
            temp->m_Next->m_Prev = temp;
        }

        delete node;
        DecrementLength();
    }

    // Delete all nodes in the list
    void LinkedListDoubly::DeleteAll()
    {
        LinkedListDoublyNode *current = m_Head;

        while (current != nullptr)
        {
            LinkedListDoublyNode *temp = current;
            current = current->m_Next;
            delete temp;
            DecrementLength();
        }

        m_Head = nullptr;
    }

    // Utility functions
    void LinkedListDoubly::IncrementLength() 
    { 
        m_Length++; 
    }
    
    void LinkedListDoubly::DecrementLength()
    {
        if (m_Length > 0)
            m_Length--;
    }

    void LinkedListDoubly::IsHeadEmpty() const
    {
        if (m_Head == nullptr)
            return;
    }

} // namespace PerformanceEvaluation
