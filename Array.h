// 1. Initializer_list {} # Array list initialization
// 2. CTAD (Class Template Argument Deduction) {1, 2, 3} #No need to specify the type
// EXP: var[0] = 1, var[1] = 2
// EXP(With): var = {1, 2, 3, 4}

// 3. Structured binding [] # Array list initialization
// struct tuple {
//     int id;
//     std::string title;
//     std::string text;
//     std::string subject;
//     std::string date;

//     tuple(const Dataset& dataset)
//         : id(dataset.m_Id), title(dataset.m_Title), text(dataset.m_Text), subject(dataset.m_Subject), date(dataset.m_Date) {

//         }
// }

//     // Structured bindings at play
//     const auto& [id, title, text, subject, date] = CleanParseAndMoreClean(line);

//     // or

//     tuple tuple = CleanParseAndMoreClean(line);
//     linked_list.insertEnd({ tuple.id, tuple.title, tuple.text, tuple.subject, tuple.date });
//         }

// 4. Operator Overloading [] # To access the index at the array
// 5. Bound-checking function # To check if the index is out of bounds
// 6. at() function with bound checking # To accept the index of the array
// 7. Iterator support # To iterate through the array
// Option 1
// for (int i = 0; i != size; i++) {
// }
// std::string f[5] = {"1", "2", "3", "4", "5"};

// // Option 2: Range-based for loops
// *(no index at all)
// *(require begin & end functions)
// for (const std::string g : f) {
//     std::cout << g << "\t";
// }

#pragma once

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <string>
#include <initializer_list>
#include <iterator>
#include "Dataset.h"

namespace PerformanceEvaluation
{
    class Array
    {
    private:
        static constexpr size_t MAX_SIZE = 25000;
        Dataset m_Array[MAX_SIZE];
        size_t m_Size = 0;

        // **Bound-checking function**
        void checkBounds(size_t index) const
        {
            if (index >= m_Size)
            {
                throw std::out_of_range("Index out of bounds");
            }
        }

    public:
        Array() = default;
        // CTAD constructor for initializer_list support
        Array(std::initializer_list<Dataset> list) : m_Size(list.size())
        {
            size_t i = 0;
            for (const auto &item : list)
            {
                m_Array[i++] = item;
            }
        }

        // Returns the dataset at the specified index
        Dataset *data() { return m_Array; }
        const Dataset *data() const { return m_Array; }

        // Overloaded [] operator with bound checking
        Dataset &operator[](size_t index)
        {
            checkBounds(index);
            return m_Array[index];
        }

        const Dataset &operator[](size_t index) const
        {
            checkBounds(index);
            return m_Array[index];
        }

        // **at() function with bound checking**
        Dataset &at(size_t index)
        {
            checkBounds(index);
            return m_Array[index];
        }

        const Dataset &at(size_t index) const
        {
            checkBounds(index);
            return m_Array[index];
        }

        // Iterator support
        Dataset *begin() {
            
                return m_Array;
            
        }
        Dataset *end();
        const Dataset *begin() const;
        const Dataset *end() const;

        void displayAll() const;
        size_t getLength() const;
        void insertEnd(const Dataset &dataset);
        void clear();
        void deleteElement(const Dataset &dataset);
        void displayFirst(int32_t count) const;
        void displayTitle() const;
        void displayText() const;
        void displaySubject() const;
        void displayDate() const;
    };
} // namespace PerformanceEvaluation
#endif // ARRAYLIST_H