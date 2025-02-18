#include <iostream>

#include "SearchLinkedList.h"

#include "SimpleConsoleLogger.h"
#include "SimpleLoggingService.h"

namespace PerformanceEvaluation
{
    LinkedListNode* SearchLinkedList::LinearSearch(std::string_view target, const LinkedList& linked_list, Criteria criteria, SearchType type) {
        LinkedListNode* temp = linked_list.getHead();
        
        auto is_found = [&, temp](std::string_view target, std::string_view dataset_str) {
            if (dataset_str.empty()) {
                SimpleConsoleLogger console;
                SimpleLoggingService::UseWarnLogger(console, "Criteria to search for target node was not specified, defaulted to empty string.");
            } 
            
            return Contains(target, dataset_str, type) ? temp : nullptr;
        };
        
        while (temp) {
            const Dataset& dataset = temp->m_Data;

            switch (criteria) {
                case Criteria::TITLE:   is_found(target, ToLowerCase(dataset.m_Title));      break;
                case Criteria::TEXT:    is_found(target, ToLowerCase(dataset.m_Text));       break;
                case Criteria::SUBJECT: is_found(target, ToLowerCase(dataset.m_Subject));    break;
                case Criteria::DATE:    is_found(target, ToLowerCase(dataset.m_Date));       break;
                default:                is_found(target, "");
            }

            temp = temp->m_Next;
        }

        return nullptr;
    } 

    LinkedList SearchLinkedList::LinearSearchAndCopy(std::string_view target, const LinkedList& linked_list, Criteria criteria, SearchType type) {
        LinkedList new_list;
        LinkedListNode* new_tail = nullptr;
        LinkedListNode* temp = linked_list.getHead();
    
        // int32_t i = 0;
        while (temp) {
            const Dataset& dataset = temp->m_Data;

            auto is_found_and_copy = [&, temp](std::string_view target, std::string_view dataset_str) {
                if (dataset_str.empty()) {
                    SimpleConsoleLogger console;
                    SimpleLoggingService::UseWarnLogger(console, "Criteria to search for target node was not specified, defaulted to empty string.");
                }
                
                if (Contains(target, dataset_str, type)) {
                    LinkedListNode* new_node = new LinkedListNode(temp->m_Data); // Deep copy
                    
                    if (!new_list.getHead()) {
                        new_list.insertEnd(new_node->m_Data);
                        new_tail = new_list.getHead();
                    } else {
                        new_tail->m_Next = new_node;
                        new_tail = new_node;
                        
                        // new_list.setLength(++i);
                    }
                }
            };

            switch (criteria) {
                case Criteria::TITLE:   is_found_and_copy(target, ToLowerCase(dataset.m_Title));   break;
                case Criteria::TEXT:    is_found_and_copy(target, ToLowerCase(dataset.m_Text));    break;
                case Criteria::SUBJECT: is_found_and_copy(target, ToLowerCase(dataset.m_Subject)); break;
                case Criteria::DATE:    is_found_and_copy(target, ToLowerCase(dataset.m_Date));    break;
                default:                is_found_and_copy(target, "");
            }

            temp = temp->m_Next;
        }

        return new_list;
    }

    void SearchLinkedList::LinearSearchAndDisplay(std::string_view target, const LinkedList& linked_list, Criteria criteria, SearchType type) {
        LinkedListNode* temp = linked_list.getHead();
        
        auto is_found_and_display = [&, temp](std::string_view target, std::string_view dataset_str) {
            if (dataset_str.empty()) {
                SimpleConsoleLogger console;
                SimpleLoggingService::UseWarnLogger(console, "Criteria to search for target node was not specified, defaulted to empty string.");
            }
            
            if (Contains(target, dataset_str, type)) {
                // temp->m_Data.Display();
                temp->Display();
            }
        };
        
        while (temp) {
            const Dataset& dataset = temp->m_Data;

            switch (criteria) {
                case Criteria::TITLE:   is_found_and_display(target, ToLowerCase(dataset.m_Title));   break;
                case Criteria::TEXT:    is_found_and_display(target, ToLowerCase(dataset.m_Text));    break;
                case Criteria::SUBJECT: is_found_and_display(target, ToLowerCase(dataset.m_Subject)); break;
                case Criteria::DATE:    is_found_and_display(target, ToLowerCase(dataset.m_Date));    break;
                default:                is_found_and_display(target, "");
            }

            temp = temp->m_Next;
        }
    }

    // void Binary(std::string_view target, LinkedList& linked_list, Criteria criteria) override {

    // }
} // namespace PerformanceEvaluation


        // if (linked_list.getHead() == nullptr) {
        //     SimpleConsoleLogger console;
        //     SimpleLoggingService::UseWarnLogger(console, "The linked list is empty.");

        //     return;
        // }

        // LinkedListNode* temp = linked_list.getHead();
        
        // while (temp != nullptr) { 
        //     Dataset dataset = temp->data;
            
        //     // switch (criteria) {
        //     //     case Criteria::TITLE:

        //             if (dataset.title.find(target) != std::string::npos) {
        //                 m_LinkedList.insertEnd(dataset);                                
        //             } 
        //         return m_LinkedList;
        //             // displayAllAfterSearch(dataset, dataset.title, target);
        //             // break;
        //         // case Criteria::TEXT:
        //         //     displayAllAfterSearch(dataset, dataset.text, target);
        //         //     break;
        //         // case Criteria::SUBJECT:
        //         //     displayAllAfterSearch(dataset, dataset.subject, target);
        //         //     break;
        //         // case Criteria::DATE:
        //         //     displayAllAfterSearch(dataset, dataset.date, target);
        //         //     break;
        //     // }

        //     // temp = temp->next;
        // };
