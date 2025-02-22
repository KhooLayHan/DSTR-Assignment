// #pragma once

// #include <iostream>

// namespace PerformanceEvaluation
// {
//     struct WordListNode {
//         std::string m_Data;
//         WordListNode* m_Next;
        
//         explicit WordListNode(const std::string& value) : m_Data(value), m_Next(nullptr) {}
//     };
    
//     template <typename T>
//     class WordList {
//     private:
//         WordListNode* m_Head;
//         WordListNode* m_Tail;

//     public:
//         WordList() : m_Head(nullptr), m_Tail(nullptr) {}



//         ~WordList() {
//             while (m_Head) {
//                 WordListNode* temp = m_Head;
//                 m_Head = m_Head->m_Next;
//                 delete temp;
//             }
//         }

//         void InsertEnd(const T& value) {
//             WordListNode* newNode = new WordListNode(value);
            
//             if (!m_Head) {
//                 m_Head = newNode;
//                 m_Tail = newNode;
//             } else {
//                 m_Tail->m_Next = newNode;
//                 m_Tail = newNode;
//             }
//         }

//         void Display() const {
//             for (const auto& word : *this) {
//                 std::cout << word << " -> ";
//             }

//             std::cout << "NULL\n";
//         }

//         size_t GetLength() const {
//             size_t length = 0;
//             WordListNode* temp = m_Head;
            
//             while (temp) {
//                 length++;
//                 temp = temp->m_Next;
//             }
            
//             return length;
//         }

//         WordListNode* GetHead() const {
//             return m_Head;
//         }
           
//         // WordList ReadAllWords() {
//         //     WordListNode* temp = m_Head;

//         //     while (temp) {
//         //         const std::string& dataset = temp->m_Data.ReadAll(); 

//         //         WordList<std::string> words;
//         //         std::regex word_pattern(R"(\b([A-Za-z0-9]+(?:-[A-Za-z0-9]+)*|(?:[A-Za-z]\.){2,})\b)");
                
//         //         std::sregex_iterator it(dataset.begin(), dataset.end(), word_pattern);
//         //         std::sregex_iterator end;

//         //         while (it != end) {
//         //             const std::string& word = it->str();

//         //             FileHandling::AppendFileNewline("./Text/assignment.txt", word);
//         //             words.InsertEnd(word);

//         //             ++it;
//         //         }

//         //         return words; 
//         //     }
//         // }

//         // 🔹 Iterator Class
//         class Iterator {
//             private:
//                 WordListNode* m_Current;
//             public:
//                 Iterator() : m_Current(nullptr) {}

//                 explicit Iterator(WordListNode* node) : m_Current(node) {}

//                 Iterator& operator++() { // Prefix increment
//                     if (m_Current) 
//                         m_Current = m_Current->m_Next;
//                     return *this;
//                 }

//                 bool operator!=(const Iterator& other) const {
//                     return m_Current != other.m_Current;
//                 }

//                 T& operator*() { 
//                     return m_Current->m_Data;
//                 }

//                 const T& operator*() const { 
//                     return m_Current->m_Data;
//                 }
//         };

//         // 🔹 Begin and End for Range-Based Loops
//         Iterator begin() { return Iterator(m_Head); }
//         const Iterator begin() const { return Iterator(m_Head); }
        
//         Iterator end() { return Iterator(nullptr); }
//         const Iterator end() const { return Iterator(nullptr); }
//     };

// } // namespace PerformanceEvaluation


#pragma once

#include <string>
#include <string_view>
#include <memory>
#include <variant>
#include <regex>

// #include "Sort.h"
// #include "Search.h"
// #include "Algorithm.h"

namespace PerformanceEvaluation {
    
    // Implement a Node structure
    struct WordListNode {
        std::string m_Data;
        WordListNode* m_Next;
        
        WordListNode(const std::string& value) 
            : m_Data(value), m_Next(nullptr) {

        }
    };
    
    // Implement the Linked List class
    class WordList {
        public:
            WordList() 
                : m_Head(nullptr), m_Length(0) {

            }
        
            WordList(const WordList& other)
                : m_Head(other.m_Head), m_Length(0) {
            }
            
            WordList(WordList&& other)
                : m_Head(std::move(other.m_Head)), m_Length(0) {
            }
            
            ~WordList() {
                WordListNode* temp;

                while (m_Head != nullptr) {
                    temp = m_Head;
                    m_Head = m_Head->m_Next;

                    delete temp;
                    temp = nullptr;
                }
            }
            
            void InsertBegin(const std::string&);
            
            void InsertEnd(const std::string&);

            void InsertPosition(const std::string&, size_t);
            
            void DisplayAll() const;
            
            // void Search(std::string_view, Criteria);

            size_t GetLength() const;
   
            // void WordList::LinearSearch(Search<WordList, WordListNode*>*, std::string_view, Criteria, SearchType);

            // void WordList::LinearSearchToCopy(std::string_view, Search<WordList, WordListNode*>*, Criteria, SearchType);
            
            // void WordList::LinearSearchToDisplay(std::string_view, Search<WordList, WordListNode*>*, Criteria, SearchType);

            // void SortBy(Sort<WordList, WordListNode*>* sort_interface);

            void DeleteNode(const std::string&);

            void DeleteAll();

            WordListNode* GetHead() const;
            
            void SetHead(WordListNode*);

        protected:
            void DecrementLength();

            void IncrementLength();

            bool Contains(const std::string&, std::string_view) const;

            void IsHeadEmpty() const;

            void IsHeadOrNextEmpty() const;
            
        private:
            WordListNode* m_Head{ nullptr };
            size_t m_Length;
    };
} // namespace PerformanceEvaluation
