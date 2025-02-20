
#include <iostream>
#include <string>
#include <string_view>
#include <memory>

#include "LinkedListDoubly.h"

#include "DateUtility.h"
#include "SimpleLogger.h"

<<<<<<< HEAD
#include "LinkedListDoubly.h"

namespace PerformanceEvaluation
{
    // Insert a new node at the beginning of the list
    void LinkedListDoubly::InsertBegin(const Dataset &dataset) {
        LinkedListDoublyNode *node = new LinkedListDoublyNode(dataset);
=======
#include "LinkedList.h"

namespace PerformanceEvaluation
{
    // Node structure for Doubly Linked List
    struct LinkedListNode {
        Dataset m_Data;
        LinkedListNode *m_Next; // Pointer to the next node
        LinkedListNode *m_Prev; // Pointer to the previous node

        LinkedListNode(const Dataset &data) : m_Data(data), m_Next(nullptr), m_Prev(nullptr) {}
    };

    // Insert a new node at the beginning of the list
    void LinkedList::insertBegin(const Dataset &dataset) {
        LinkedListNode *node = new LinkedListNode(dataset);
>>>>>>> origin/KhooLayHan_2
        node->m_Next = m_Head;

        if (m_Head != nullptr){
            m_Head->m_Prev = node;
        }

        m_Head = node;

<<<<<<< HEAD
        IncrementLength();
    }

    // Insert a new node at the end of the list
    void LinkedListDoubly::InsertEnd(const Dataset &dataset) {
        LinkedListDoublyNode *node = new LinkedListDoublyNode(dataset);
=======
        incrementLength();
    }

    // Insert a new node at the end of the list
    void LinkedList::insertEnd(const Dataset &dataset) {
        LinkedListNode *node = new LinkedListNode(dataset);
>>>>>>> origin/KhooLayHan_2

        if (m_Head == nullptr)
        {
            m_Head = node;
<<<<<<< HEAD
            IncrementLength();
            return;
        }

        LinkedListDoublyNode *temp = m_Head;
=======
            incrementLength();
            return;
        }

        LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2

        // Traverse to the last node
        while (temp->m_Next != nullptr)
        {
            temp = temp->m_Next;
        }

        temp->m_Next = node;
        node->m_Prev = temp;

<<<<<<< HEAD
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
=======
        incrementLength();
    }

    // Insert a new node at a specific position
    void LinkedList::insertPosition(const Dataset &dataset, size_t position) {
        LinkedListNode *node = new LinkedListNode(dataset);

        if (position == 0) {
            insertBegin(dataset);
            return;
        }

        LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2

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

<<<<<<< HEAD
        IncrementLength();
    }

    // Display all nodes in the linked list
    void LinkedListDoubly::DisplayAll() const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
=======
        incrementLength();
    }

    // Display all nodes in the linked list
    void LinkedList::displayAll() const {
        isHeadEmpty();

        LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2

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
<<<<<<< HEAD
    void LinkedListDoubly::DisplayFirst(int32_t count) const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
=======
    void LinkedList::displayFirst(int32_t count) const {
        isHeadEmpty();

        LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2
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
<<<<<<< HEAD
    void LinkedListDoubly::DisplayTitle() const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
=======
    void LinkedList::displayTitle() const {
        isHeadEmpty();

        LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2
        std::cout << "TITLE\n-----------\n";

        while (temp != nullptr)
        {
            std::cout << temp->m_Data.m_Title << "\n";
            temp = temp->m_Next;
        }

        std::cout << "\n";
    }

    // Display only the text content of all articles
<<<<<<< HEAD
    void LinkedListDoubly::DisplayText() const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
=======
    void LinkedList::displayText() const {
        isHeadEmpty();

        LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2
        std::cout << "TEXT\n-----------\n";

        while (temp != nullptr)
        {
            std::cout << temp->m_Data.m_Text << "\n";
            temp = temp->m_Next;
        }

        std::cout << "\n";
    }

    // Display only the subjects of all articles
<<<<<<< HEAD
    void LinkedListDoubly::DisplaySubject() const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
=======
    void LinkedList::displaySubject() const {
        isHeadEmpty();

        LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2
        std::cout << "SUBJECT\n-----------\n";

        while (temp != nullptr)
        {
            std::cout << temp->m_Data.m_Subject << "\n";
            temp = temp->m_Next;
        }

        std::cout << "\n";
    }

    // Display only the publication dates of all articles
<<<<<<< HEAD
    void LinkedListDoubly::DisplayDate() const {
        IsHeadEmpty();

        LinkedListDoublyNode *temp = m_Head;
=======
    void LinkedList::displayDate() const {
        isHeadEmpty();

        LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2
        std::cout << "DATE\n-----------\n";

        while (temp != nullptr)
        {
            std::cout << temp->m_Data.m_Date << "\n";
            temp = temp->m_Next;
        }

        std::cout << "\n";
    }

    // Get the total number of articles in the linked list
<<<<<<< HEAD
    size_t LinkedListDoubly::GetLength() const {
        size_t length = 0;
        LinkedListDoublyNode *temp = m_Head;
=======
    size_t LinkedList::getLength() const {
        size_t length = 0;
        LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2

        while (temp)
        {
            length++;
            temp = temp->m_Next;
        }

        return length;
    }

    // Delete a specific node from the list
<<<<<<< HEAD
    void LinkedListDoubly::DeleteNode(const Dataset &dataset) {
=======
    void LinkedList::deleteNode(const Dataset &dataset) {
>>>>>>> origin/KhooLayHan_2
        if (m_Head == nullptr)
            return;

        if (m_Head->m_Data == dataset) {
<<<<<<< HEAD
            LinkedListDoublyNode *temp = m_Head;
=======
            LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2
            m_Head = m_Head->m_Next;

            if (m_Head != nullptr)
            {
                m_Head->m_Prev = nullptr;
            }

            delete temp;
<<<<<<< HEAD
            DecrementLength();
            return;
        }

        LinkedListDoublyNode *temp = m_Head;
=======
            decrementLength();
            return;
        }

        LinkedListNode *temp = m_Head;
>>>>>>> origin/KhooLayHan_2
        while (temp->m_Next != nullptr && !(temp->m_Next->m_Data == dataset))
        {
            temp = temp->m_Next;
        }

        if (temp->m_Next == nullptr)
            return;

<<<<<<< HEAD
        LinkedListDoublyNode *node = temp->m_Next;
=======
        LinkedListNode *node = temp->m_Next;
>>>>>>> origin/KhooLayHan_2
        temp->m_Next = temp->m_Next->m_Next;

        if (temp->m_Next != nullptr)
        {
            temp->m_Next->m_Prev = temp;
        }

        delete node;
<<<<<<< HEAD
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
=======
        decrementLength();
    }

    // Delete all nodes in the list
    void LinkedList::deleteAll()
    {
        LinkedListNode *current = m_Head;

        while (current != nullptr)
        {
            LinkedListNode *temp = current;
            current = current->m_Next;
            delete temp;
            decrementLength();
>>>>>>> origin/KhooLayHan_2
        }

        m_Head = nullptr;
    }

    // Utility functions
<<<<<<< HEAD
    void LinkedListDoubly::IncrementLength() { m_Length++; }
    void LinkedListDoubly::DecrementLength()
=======
    void LinkedList::incrementLength() { m_Length++; }
    void LinkedList::decrementLength()
>>>>>>> origin/KhooLayHan_2
    {
        if (m_Length > 0)
            m_Length--;
    }
<<<<<<< HEAD
    void LinkedListDoubly::IsHeadEmpty() const
=======
    void LinkedList::isHeadEmpty() const
>>>>>>> origin/KhooLayHan_2
    {
        if (m_Head == nullptr)
            return;
    }

} // namespace PerformanceEvaluation
