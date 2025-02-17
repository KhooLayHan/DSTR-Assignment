#pragma once

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <string>
#include <string_view>
#include <memory>

#include "Dataset.h"
#include "LinkedList.h"

// #include "Search.h"
// #include "SearchLinkedList.h"
// #include "Sort.h"
// #include "SortMergeLinkedList.h"

namespace PerformanceEvaluation {
    
    // Implement a Node structure
    struct LinkedListNode {
        Dataset m_Data;
        LinkedListNode* m_Next;

        LinkedListNode(const Dataset& value) 
            : m_Data(value), m_Next(nullptr) {

        }
    };
    
    // Implement the Linked List class
    class LinkedList {
        public:
            LinkedList() 
                : m_Head(nullptr), m_Length(0) {

            }
        
            LinkedList(const LinkedList& other)
                : m_Head(other.m_Head), m_Length(0) {
            }
            
            LinkedList(LinkedList&& other)
                : m_Head(std::move(other.m_Head)), m_Length(0) {
            }

            ~LinkedList() {
                LinkedListNode* current = m_Head;

                while (current != nullptr) {
                    LinkedListNode* next = current->m_Next;
                    delete current;
                    current = next;
                    
                    // temp = m_Head;
                    // m_Head = m_Head->m_Next;

                    // delete temp;
                    // temp = nullptr;
                }
            }

            void insertBegin(const Dataset&);
            
            void insertEnd(const Dataset&);

            void insertPosition(const Dataset&, size_t);
            
            void displayAll() const;
            
            void displayFirst(int32_t count = 10) const;

            void displayTitle() const;

            void displayText() const;
            
            void displaySubject() const;

            void displayDate() const;

            void displayLength(std::string_view) const;

            void displayLengthTrueDataset() const;

            void displayLengthFakeDataset() const;
            
            size_t getLength() const;
            
            // using Searched = PerformanceEvaluation::Search<LinkedList, LinkedListNode*>;
            // using Sorted = PerformanceEvaluation::Sort<LinkedList, LinkedListNode*>;

            // void LinearSearch(const std::unique_ptr<Searched>&, std::string_view, Criteria);
            // void LinearSearchToCopy(std::string_view, const std::unique_ptr<Searched>&, Criteria);
            // void LinearSearchToDisplay(std::string_view, const std::unique_ptr<Searched>&, Criteria);

            // void SortBy(const std::unique_ptr<Sort<LinkedList, LinkedListNode*>>&);

            void deleteNode(const Dataset&);

            void deleteAll();

            LinkedListNode* getHead() const;
            
            void setHead(LinkedListNode*);

            void setLength(size_t length) { 
                m_Length = length; 
            }
        protected:
            void decrementLength();

            void incrementLength();

            bool contains(const std::string&, std::string_view) const;

            void isHeadEmpty() const;

            void isHeadOrNextEmpty() const;
            
        public:
            LinkedListNode* m_Head = nullptr;

        private:
            size_t m_Length;
    };
} // namespace PerformanceEvaluation

#endif