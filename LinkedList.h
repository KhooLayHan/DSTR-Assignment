#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <string_view>
#include <memory>
#include <variant>

#include "Dataset.h"
#include "VariantHelpers.h"

namespace PerformanceEvaluation {
    
    // Implement a Node structure
    struct LinkedListNode {
        // DataVariant m_Data;
        Dataset m_Data;
        LinkedListNode* m_Next;
        
        explicit LinkedListNode(const Dataset& value) 
            : m_Data(std::move(value)), m_Next(nullptr) {

        }

        // void Display() const {
        //     std::cout << "\n\033[34;1mID:\033[0m "       << m_Data.m_Id      << "\n";
        //     std::cout << "\033[34;1mTITLE:\033[0m "      << m_Data.m_Title   << "\n";
        //     std::cout << "\033[34;1mTEXT:\033[0m "       << m_Data.m_Text    << "\n";
        //     std::cout << "\033[34;1mSUBJECT:\033[0m "    << m_Data.m_Subject << "\n";
        //     std::cout << "\033[34;1mDATE:\033[0m "       << m_Data.m_Date    << "\n";
            
        //     std::cout << "\n-----------\n";
        // }

        // void Display() const {
        //     std::cout << "\n\033[34;1mID:\033[0m " << m_Data << "\n";
        // }
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
                    m_Head = m_Head->m_Next;

                    delete temp;
                    temp = nullptr;
                }
            }

            // void InsertBegin(const DataVariant&);
            
            // void InsertEnd(const DataVariant&);

            // void InsertPosition(const DataVariant&, size_t);
            
            void InsertBegin(const Dataset&);
            
            void InsertEnd(const Dataset&);

            void InsertPosition(const Dataset&, size_t);
            
            void DisplayAll() const;
            
            void DisplayFirst(int32_t count = 10) const;

            void DisplayTitle() const;

            void DisplayText() const;
            
            void DisplaySubject() const;

            void DisplayDate() const;

            void Search(std::string_view, Criteria);

            void DisplayLength(std::string_view) const;

            void DisplayLengthTrueDataset() const;

            void DisplayLengthFakeDataset() const;
            
            size_t GetLength() const;

            void MergeSort();

            void DeleteNode(const Dataset&);

            void DeleteAll();

            LinkedListNode* GetHead() const;
            
            void SetHead(LinkedListNode*);

        protected:
            void DecrementLength();

            void IncrementLength();

            bool Contains(const std::string&, std::string_view) const;

            void IsHeadEmpty() const;

            void IsHeadOrNextEmpty() const;
            
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
