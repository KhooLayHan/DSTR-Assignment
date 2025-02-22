#pragma once

#include <string>
#include <string_view>

#include "Array.h"
#include "LinkedList.h"
#include "WordList.h"

namespace PerformanceEvaluation
{
    enum class SearchType {
        PARTIAL = 0,
        IMPARTIAL = 1,
    };

    template<typename T, typename N = nullptr_t>
    class Search {
        public:
            N UseLinearSearchAlgorithm(std::string_view target, const T& linked_list, Criteria criteria, SearchType type) {
                return LinearSearch(target, linked_list, criteria, type);
            }
            
            T UseLinearSearchAndCopyAlgorithm(std::string_view target, const T& linked_list, Criteria criteria, SearchType type) {
                return LinearSearchAndCopy(target, linked_list, criteria, type);
            }
            
            void UseLinearSearchAndDisplayAlgorithm(std::string_view target, const T& linked_list, Criteria criteria, SearchType type) {
                LinearSearchAndDisplay(target, linked_list, criteria, type);
            }
    
            // For Word Linked List
            N UseLinearSearchWordAlgorithm(std::string_view target, const T& linked_list, SearchType type) {
                // return LinearSearchWord(target, linked_list, type);
            }

            T UseLinearSearchWordAndCopyAlgorithm(std::string_view target, const T& linked_list, SearchType type) {
                // return LinearSearchWordAndCopy(target, linked_list, type);
                // return T();
                return {};
            }
            
            void UseLinearSearchWordAndDisplayAlgorithm(std::string_view target, const T& linked_list, SearchType type) {
                // return LinearSearchWordAndDisplay(target, linked_list, type);
            }

            virtual ~Search() = default;
        protected:
            constexpr bool Contains(std::string_view target, std::string_view dataset_str, SearchType type) {
                switch (type) {
                    case SearchType::IMPARTIAL: return dataset_str.find(target) != std::string::npos;
                    case SearchType::PARTIAL:   return dataset_str == target;
                    default:                    return false; 
                };

                return false;
            }

            // Custom Transform function inspired by std::transform()
            template <typename InputIterator, typename OutputIterator, typename UnaryFunction>
            void Transform(InputIterator first, InputIterator last, OutputIterator out, UnaryFunction func) {
                while (first != last) {
                    (*out)++ = func((*first)++); // Apply function and copy the result
                }
            }

            // To convert an entire string to lowercase
            constexpr std::string ToLowerCase(std::string_view dataset) {
                std::string result;
                // dataset.size(), ""
                // result.length() += dataset.size();

                for (const auto& character : dataset) {
                    result += std::tolower(character);
                }

                return result;
            }

            // void SearchByCriteria(const Dataset& dataset, Criteria criteria, std::string_view target, auto (*is_found)(std::string_view, std::string_view)) {
            //     auto found = [](std::string_view target, ){ is_found(target, dataset) };

            //     switch (criteria) {
            //         case Criteria::TITLE:   found;      break;
            //         case Criteria::TEXT:    is_found(target, ToLowerCase(dataset.m_Text));       break;
            //         case Criteria::SUBJECT: is_found(target, ToLowerCase(dataset.m_Subject));    break;
            //         case Criteria::DATE:    is_found(target, ToLowerCase(dataset.m_Date));       break;
            //         default:                is_found(target, "");
            //     }
            // }
        private:
            virtual N       LinearSearch            (std::string_view, const T&, Criteria, SearchType) = 0;
            virtual T       LinearSearchAndCopy     (std::string_view, const T&, Criteria, SearchType) = 0;
            virtual void    LinearSearchAndDisplay  (std::string_view, const T&, Criteria, SearchType) = 0;
            
            // virtual N       LinearSearchWord            (std::string_view, const T&, SearchType) = 0;
            // virtual T       LinearSearchWordAndCopy     (std::string_view, const T&, SearchType) = 0;
            // virtual void    LinearSearchWordAndDisplay  (std::string_view, const T&, SearchType) = 0;
            
            // virtual T       BinarySearch            (std::string_view, const T&, Criteria) = 0;
            // virtual T       BinarySearchAndCopy     (std::string_view, const T&, Criteria) = 0;
            // virtual void    BinarySearchAndDisplay  (std::string_view, const T&, Criteria) = 0;
    };
} // namespace PerformanceEvaluation
