#include "Algorithm.h"

namespace PerformanceEvaluation {
    // Singly Linked List Searching
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

    // Doubly Linked List searching
    LinkedListDoublyNode* Algorithm::LinearSearch(LinkedListDoubly& linked_list_doubly, Search<LinkedListDoubly, LinkedListDoublyNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            return search_interface->UseLinearSearchAlgorithm(target, linked_list_doubly, criteria, type);
        }

        return nullptr;
    }

    LinkedListDoubly Algorithm::LinearSearchAndCopy(LinkedListDoubly& linked_list_doubly, Search<LinkedListDoubly, LinkedListDoublyNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            return search_interface->UseLinearSearchAndCopyAlgorithm(target, linked_list_doubly, criteria, type);
        }

        return {};
    }
    
    void Algorithm::LinearSearchAndDisplay(LinkedListDoubly& linked_list_doubly, Search<LinkedListDoubly, LinkedListDoublyNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            search_interface->UseLinearSearchAndDisplayAlgorithm(target, linked_list_doubly, criteria, type);
        }
    }

    // Sorting
    void Algorithm::SortBy(LinkedList& linked_list, Sort<LinkedList, LinkedListNode*>* sort_interface) {
        if (sort_interface) {
            sort_interface->UseSortingAlgorithm(linked_list);
        }
    }

    // void Algorithm::SortBy(LinkedListDoubly& linked_list_doubly, Sort<LinkedListDoubly, LinkedListDoublyNode*>* sort_interface) {
    //     if (sort_interface) {
    //         sort_interface->UseSortingAlgorithm(linked_list_doubly);
    //     }
    // }

    
    WordList Algorithm::LinearSearchWordAndCopy(WordList& linked_list, Search<WordList, WordListNode*>* search_interface, std::string_view target, SearchType type) {
        if (search_interface) {
            return search_interface->UseLinearSearchWordAndCopyAlgorithm(target, linked_list, type);
        }

        return {};
    }

    void Algorithm::SortBy(WordList& linked_list, Sort<WordList, WordListNode*>* sort_interface) {
        if (sort_interface) {
            sort_interface->UseSortingAlgorithm(linked_list);
        }
    };
} // namespace PerformanceEvaluation
