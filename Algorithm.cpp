#include "Algorithm.h"

namespace PerformanceEvaluation {
    // Singly Linked List Linear Search
    LinkedListNode* Algorithm::LinearSearch(LinkedList& linked_list, Search<LinkedList, LinkedListNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            return search_interface->UseLinearSearchAlgorithm(target, linked_list, criteria, type);
        }

        return nullptr;
    }

    LinkedList Algorithm::LinearSearchAndCopy(LinkedList& linked_list, Search<LinkedList, LinkedListNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            return search_interface->UseLinearSearchAndCopyAlgorithm(target, linked_list, criteria, type);
        }

        return {};
    }
    
    void Algorithm::LinearSearchAndDisplay(LinkedList& linked_list, Search<LinkedList, LinkedListNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            search_interface->UseLinearSearchAndDisplayAlgorithm(target, linked_list, criteria, type);
        }
    }
    
    // Singly Linked List Binary Search
    LinkedListNode* Algorithm::BinarySearch(LinkedList& linked_list, Search<LinkedList, LinkedListNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            return search_interface->UseBinarySearchAlgorithm(target, linked_list, criteria, type);
        }
        
        return nullptr;
    }
    
    LinkedList Algorithm::BinarySearchAndCopy(LinkedList& linked_list, Search<LinkedList, LinkedListNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            return search_interface->UseBinarySearchAndCopyAlgorithm(target, linked_list, criteria, type);
        }

        return {};
    }
    
    void Algorithm::BinarySearchAndDisplay(LinkedList& linked_list, Search<LinkedList, LinkedListNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            search_interface->UseBinarySearchAndDisplayAlgorithm(target, linked_list, criteria, type);
        }
    }

    // Sorting
    void Algorithm::SortBy(LinkedList& linked_list, Sort<LinkedList, LinkedListNode*>* sort_interface) {
        if (sort_interface) {
            sort_interface->UseSortingAlgorithm(linked_list);
        }
    }

    void Algorithm::SortBy(Array<Dataset>& array, Sort<Array<Dataset>>* sorter) {
        if (sorter) {
            sorter->UseSortingAlgorithm(array);
        }
    }
} // namespace PerformanceEvaluation
