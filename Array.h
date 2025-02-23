#pragma once

#include <cassert>
#include <array>
#include <iostream>
#include <string>
#include <memory> 

#include "Dataset.h"
namespace PerformanceEvaluation {

    // * Minimum structure for Array implementation, can add more if willing
    
    struct ArrayData {
        std::string data;
        size_t length;
        size_t capacity;
    };
    
    template <typename T, size_t Length = 25000>
    class Array {
        public:
        // TODO: Write the implementation code here...

        // ! Prefer array implementation to have bounds-checking
        
            Array() : m_Size(0) {}
            
            // Array() : m_Size(0) {}

            // Array() : m_Data(), (0) {} // Default constructor

            // ✅ Copy constructor for safe copying
            Array(const Array& other) : m_Size(other.m_Size) {
                for (size_t i = 0; i < other.m_Size; i++) {
                    m_Data[i] = other.m_Data[i];
                }
            }

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
            // void DisplayFirst(int32_t count) const;

            
            void DisplayFirst(size_t count) const {
                if (m_Size == 0) {
                    std::cout << "Array is empty.\n";
                    return;
                }
            
                size_t limit = (count > m_Size) ? m_Size : count; // Ensure we don't exceed the stored elements
            
                for (size_t i = 0; i < limit; i++) {
                    std::cout << "\n\033[34;1mID:\033[0m "       << m_Data[i].m_Id      << "\n";
                    std::cout << "\033[34;1mTITLE:\033[0m "      << m_Data[i].m_Title   << "\n";
                    std::cout << "\033[34;1mTEXT:\033[0m "       << m_Data[i].m_Text    << "\n";
                    std::cout << "\033[34;1mSUBJECT:\033[0m "    << m_Data[i].m_Subject << "\n";
                    std::cout << "\033[34;1mDATE:\033[0m "       << m_Data[i].m_Date    << "\n";
                }
            
                std::cout << "\n";
            }

            void InsertEnd(const T& value) {
                if (m_Size < Length) {
                    m_Data[m_Size++] = value;
                } else {
                    //std::cerr << "Array is full. Cannot insert more elements." << std::endl;
                    return;
                }
            }

            void DisplayLength(std::string_view file_path) const {
                std::cout << "The total number of elements in the array from " << file_path << " dataset is "
                    << m_Size << ".\n";
            }

            // double CalculateFakeNewsPercentage(const Array<Dataset>& trueDataset, const Array<Dataset>& fakeDataset) {
            //     size_t totalPolitical2016 = 0;
            //     size_t fakePolitical2016 = 0;
            
            //     // Lambda function to process dataset
            //     auto processDataset = [&](const Array<Dataset>& dataset, bool isFake) {
            //         for (size_t i = 0; i < dataset.Size(); i++) {
            //             const Dataset& article = dataset[i];
            
            //             // Check if the article is from 2016 and related to politics
            //             if (article.m_Date.find("2016") != std::string::npos && 
            //                 article.m_Subject.find("politics") != std::string::npos) {
            //                 totalPolitical2016++;  // Count valid political news
            //                 if (isFake) fakePolitical2016++;  // Count only fake news
            //             }
            //         }
            //     };
            
            //     // Process both datasets
            //     processDataset(trueDataset, false);
            //     processDataset(fakeDataset, true);
            
            //     // Avoid division by zero
            //     if (totalPolitical2016 == 0) return 0.0;
            
            //     return (static_cast<double>(fakePolitical2016) / totalPolitical2016) * 100.0;
            // }

            // double CalculateFakeNewsPercentageLinear(const Array<Dataset> &true_news, const Array<Dataset> &fake_news) {
            //     int fake_political_count = 0;
            //     int total_political_count = 0;
    
            //     for (const auto &article : fake_news) {
            //         if (article.m_Subject == "politics" && article.m_Date == "2016") {
            //             fake_political_count++;
            //         }
            //     }
    
            //     for (const auto &article : true_news) {
            //         if (article.m_Subject == "politics" && article.m_Date == "2016") {
            //             total_political_count++;
            //         }
            //     }
    
            //     total_political_count += fake_political_count;
    
            //     if (total_political_count == 0) return 0.0;
    
            //     return (static_cast<double>(fake_political_count) / total_political_count) * 100;
            // }
    
            // bool BinarySearch(const Array<Dataset> &dataset, const std::string &subject, const std::string &date) {
            //     int left = 0, right = dataset.Size() - 1;
    
            //     while (left <= right) {
            //         int mid = left + (right - left) / 2;
    
            //         if (dataset[mid].m_Subject == subject && dataset[mid].m_Date == date) {
            //             return true;
            //         } 
            //         else if (dataset[mid].m_Subject < subject || 
            //                 (dataset[mid].m_Subject == subject && dataset[mid].m_Date < date)) {
            //             left = mid + 1;
            //         } 
            //         else {
            //             right = mid - 1;
            //         }
            //     }
            //     return false;
            // }

            T* getHead() const {
                return m_Data;
            }

            T* Data() {
                return m_Data;  // Return pointer to first element
            }

            size_t Size() const {
                return m_Size;
            }

            T* begin() { return m_Data; }
            T* end() { return m_Data + m_Size; }

            const T* begin() const { return m_Data; }
            const T* end() const { return m_Data + m_Size; }

            void DeleteElement(const T&);
        private:
            T m_Data[Length]; // To accept any type 
            size_t m_Size;    // Number of elements currently in array
    };

} // namespace PerformanceEvaluation