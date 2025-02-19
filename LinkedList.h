#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <string_view>
#include <memory>

#include "Dataset.h"

namespace PerformanceEvaluation {
    
    // Implement a Node structure
    struct LinkedListNode {
        Dataset data;
        LinkedListNode* next;

        LinkedListNode(const Dataset& value) 
            : data(value), next(nullptr) {

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
                LinkedListNode* temp;

                while (m_Head != nullptr) {
                    temp = m_Head;
                    m_Head = m_Head->next;

                    delete temp;
                    temp = nullptr;
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

            void mergeSort();

            void deleteNode(const Dataset&);

            void deleteAll();

            LinkedListNode* getHead() const;
            
            void setHead(LinkedListNode*);

        protected:
            void decrementLength();

            void incrementLength();

            constexpr bool contains(const std::string&, std::string_view) const;

            void isHeadEmpty() const;

            void isHeadOrNextEmpty() const;
            
            // Helper function to split the linked list into two halves
            LinkedListNode* getMiddle(LinkedListNode*);

            // Helper function to merge two sorted linked lists 
            LinkedListNode* merge(LinkedListNode*, LinkedListNode*);

            // Applies merge sort recursively 
            LinkedListNode* mergeSort(LinkedListNode*);

        private:
            LinkedListNode* m_Head{ nullptr };
            size_t m_Length;
    };
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

#endif

       // void displayAfterSearch(const std::string& source, std::string_view target) {
            //     if (contains(source, target)) 
            //         SimpleLogger::Info("Found: " + source, LogHandler::FILE);
            // }    

            // void displayAllAfterSearch(const Dataset& dataset, const std::string& source, std::string_view target) {
            //     if (contains(source, target)) {
            //         SimpleLogger::Info(dataset.display(), LogHandler::FILE);
                    
            //         // FileHandling::appendFile("./Logs/log_test.txt", source);  
            //     }    
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

            // std::string substring(const std::string& data, size_t index) {
            //     if (index != std::string::npos) 
            //         return data.substr(index);
                
            //     SimpleLogger::Warn("Target index was not found.", LogHandler::FILE);
            //     return "";
            // }
