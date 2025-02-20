#pragma once

#include <cassert>
#include <array>
#include <iostream>
#include <string>

#include "Dataset.h"
namespace PerformanceEvaluation {

    // * Minimum structure for Array implementation, can add more if willing
    
    struct ArrayData {
        std::string data;
        size_t length;
        size_t capacity;
    };
    
    template <typename T, size_t Length>
    class Array {
        public:
        // TODO: Write the implementation code here...

        // ! Prefer array implementation to have bounds-checking
        
            Array() {} // Default constructor
            
            Array(const T& data) : m_Data(data) {} 

            ~Array() {} // Destructor
            
            // Overloading [] operator
            constexpr T& operator[](size_t index) noexcept {
                assert(index < Length && "Index specified is out of bounds!");

                return m_Data[index];
            }

            constexpr const T& operator[](size_t index) const noexcept {
                assert(index < Length && "Index specified is out of bounds!");

                return m_Data[index];
            }
            
            // SAMPLE MEMBER FUNCTIONS
            void DisplayFirst(int32_t count) const;

            void InsertEnd(const T&);

            void DeleteElement(const T&);
        private:
            T m_Data[Length]; // To accept any type 
    };

} // namespace PerformanceEvaluation