// #pragma once

// #include <iostream>
// #include <string>
// #include <string_view>
// #include <memory>

// #include "Algorithms.cpp"
// #include "Dataset.cpp"
// #include "DateUtility.cpp"
// #include "SimpleLogger.h"

// namespace PerformanceEvaluation {
    
//     // Implement a Node structure
//     // template <typename T>
//     struct LinkedListNode {
//         Dataset data;
//         LinkedListNode* next;

//         LinkedListNode(const Dataset& value) 
//             : data(value), next(nullptr) {

//         }
//     };
    
//     // Implement the Linked List class
//     // template <typename T>
//     class LinkedList : public Algorithms {
//         public:
//             LinkedList() 
//                 : head(nullptr), length(0) {

//             }
        
//             LinkedList(const LinkedList& other)
//                 : head(other.head), length(0) {
//             }
            
//             LinkedList(LinkedList&& other)
//                 : head(other.head), length(0) {
//             }
            
//             void insertBegin(const Dataset& dataset) {
//                 LinkedListNode* node = new LinkedListNode(dataset);
//                 node->next = head;
//                 head = node;
                
//                 length++;
//             }
            
//             void insertEnd(const Dataset& dataset) {
//                 LinkedListNode* node = new LinkedListNode(dataset);

//                 if (head == nullptr) {
//                     head = node;
//                     length++;

//                     return;
//                 }

//                 LinkedListNode* temp = head;
                
//                 while (temp->next != nullptr) {
//                     temp = temp->next;
//                 }

//                 temp->next = node;

//                 length++;
//             }

//             void insertPosition(const Dataset& dataset, size_t position) {
//                 LinkedListNode* node = new LinkedListNode(dataset);

//                 if (position == 0) {
//                     insertBegin(dataset);
//                     return;
//                 }

//                 LinkedListNode* temp = head;
//                 for (size_t i = 0; temp != nullptr && i < position - i; i++) 
//                     temp = temp->next;

//                 if (temp == nullptr) {
//                     SimpleLogger::Fatal("Position is out of bounds.", LogHandler::FILE);
//                     delete node;
//                     return;
//                 }

//                 node->next = temp->next;
//                 temp->next = node;

//                 length++;
//             }
            
//             void displayAll() {
//                 isHeadEmpty();

//                 LinkedListNode* temp = head;

//                 while (temp != nullptr) {
//                     std::cout << "ID: "         << temp->data.id      << "\n";
//                     std::cout << "TITLE: "      << temp->data.title   << "\n";
//                     std::cout << "TEXT: "       << temp->data.text    << "\n";
//                     std::cout << "SUBJECT: "    << temp->data.subject << "\n";
//                     std::cout << "DATE: "       << temp->data.date    << "\n";
                    
//                     std::cout << "\n-----------\n\n";
//                     temp = temp->next;
//                 } 

//                 std::cout << "\n";
//             }
            
//             void displayTitle() {
//                 isHeadEmpty();

//                 LinkedListNode* temp = head;

//                 std::cout << "TITLE\n-----------\n";
                
//                 while (temp != nullptr) {
//                     SimpleLogger::Info(temp->data.title, LogHandler::FILE);
//                     // std::cout << temp->data.title << "\n";
//                     temp = temp->next;
//                 } 
                
//                 std::cout << "\n";
//             }

//             void displayText() {
//                 isHeadEmpty();

//                 LinkedListNode* temp = head;

//                 std::cout << "TEXT\n-----------\n";

//                 while (temp != nullptr) {
//                     std::cout << temp->data.text << "\n";
//                     temp = temp->next;
//                 } 

//                 std::cout << "\n";
//             }
            
//             void displaySubject() {
//                 isHeadEmpty();

//                 LinkedListNode* temp = head;
                
//                 std::cout << "SUBJECT\n-----------\n";
                
//                 while (temp != nullptr) {
//                     std::cout << temp->data.subject << "\n";
//                     temp = temp->next;
//                 } 

//                 std::cout << "\n";
//             }

//             void displayDate() {
//                 isHeadEmpty();

//                 LinkedListNode* temp = head;

//                 std::cout << "DATE\n-----------\n";

//                 while (temp != nullptr) {
                    
//                     SimpleLogger::Info(temp->data.date, LogHandler::FILE);
                
//                     // std::cout << temp->data.date << "\n";
//                     temp = temp->next;
//                 } 

//                 std::cout << "\n";
//             }

//             void search(std::string_view target, Criteria criteria) {
//                 // static constexpr bool is_string_v = std::is_same_v<std::decay_t<T>, std::string>;
//                 isHeadEmpty();

//                 LinkedListNode* temp = head;

//                 while (temp != nullptr) { 
//                     Dataset dataset = temp->data;
                    
//                     switch (criteria) {
//                         case Criteria::TITLE:
//                             displayAllAfterSearch(dataset, dataset.title, target);
//                             break;
//                         case Criteria::TEXT:
//                             displayAllAfterSearch(dataset, dataset.text, target);
//                             break;
//                         case Criteria::SUBJECT:
//                             displayAllAfterSearch(dataset, dataset.subject, target);
//                             break;
//                         case Criteria::DATE:
//                             displayAllAfterSearch(dataset, dataset.date, target);
//                             break;
//                     }

//                     // switch (criteria) {
//                     //     case Criteria::TITLE:
//                     //         displayAllAfterSearch(temp->data, target, criteria);
//                     //         break;
//                     //     case Criteria::TEXT:
//                     //         displayAllAfterSearch(temp->data, target, criteria);
//                     //         break;
//                     //     case Criteria::SUBJECT:
//                     //         displayAllAfterSearch(temp->data, target, criteria);
//                     //         break;
//                     //     case Criteria::DATE:
//                     //         displayAllAfterSearch(temp->data, target, criteria);
//                     //         break;
//                     // }
                    
//                     // size_t index = findTargetIndex(temp->data, criteria, target);
                    
//                     // SimpleLogger::Info(substringByIndex(temp->data, criteria, index), LogHandler::FILE);
                    
//                     // std::cout << substringByIndex(temp->data, criteria, index) << "\n";
            
//                     temp = temp->next;
//                 };
//             }

//             void displayAfterSearch(const std::string& source, std::string_view target) {
//                 if (contains(source, target)) 
//                     SimpleLogger::Info("Found: " + source, LogHandler::FILE);
//             }    

//             void displayAllAfterSearch(const Dataset& dataset, const std::string& source, std::string_view target) {
//                 if (contains(source, target)) {
//                     SimpleLogger::Info(dataset.display(), LogHandler::FILE);
                    
//                     // FileHandling::appendFile("./Logs/log_test.txt", source);  
//                 }    
//             }    

//             size_t getLength() const {
//                 // static size_t length = 0;
//                 // LinkedListNode* temp = head;
                
//                 // while (temp) {
//                 //     length++;
//                 //     temp = temp->next;
//                 // }

//                 return length;
//             }

//             // void bubbleSort() override {
//             //     if (head == nullptr || head->next == nullptr) {
//             //         SimpleLogger::Info("List only has 0 or 1 elements, cannot be sorted.", LogHandler::FILE);
//             //         return;
//             //     }

//             //     bool swapped = true;

//             //     LinkedListNode* temp;
//             //     LinkedListNode* last_sorted = nullptr;

//             //     do {
//             //         swapped = false;
//             //         temp = head;

//             //         while (temp->next != last_sorted) {
//             //             if (temp->data > )
//             //         }
//             //     }
//             // }

//             void mergeSort() {
//                 head = mergeSort(head);
//             }

//             void deleteNode(const Dataset& dataset) {
//                 if (head == nullptr) {
//                     SimpleLogger::Info("List is empty.", LogHandler::FILE);
//                     return;
//                 }

//                 if (head->data == dataset) {
//                     LinkedListNode* temp = head;
//                     head = head->next;
//                     delete temp;

//                     length--;
//                     return;
//                 }

//                 LinkedListNode* temp = head;
                
//                 while (temp->next != nullptr && !(temp->next->data == dataset)) {
//                     temp = temp->next;
//                 }

//                 if (temp->next == nullptr) { 
//                     SimpleLogger::Warn("Value cannot be found in the list.", LogHandler::FILE);
//                     return;
//                 }

//                 // Node to be deleted
//                 LinkedListNode* node = temp->next;
//                 temp->next = temp->next->next;
//                 delete node;

//                 length--;
//             }

//             void deleteAll() {
//                 LinkedListNode* current = head;

//                 while (current != nullptr) {
//                     LinkedListNode* temp = current;
//                     current = current->next;
                    
//                     // SimpleLogger::Info("Node has been deleted." + temp->data.title, LogHandler::CONSOLE);
//                     delete temp;

//                     length--;
//                 }

//                 head = nullptr;
//                 SimpleLogger::Info("All nodes has been deleted.", LogHandler::FILE);
//             }

//             ~LinkedList() {
//                 LinkedListNode* temp;

//                 while (head != nullptr) {
//                     temp = head;
//                     head = head->next;

//                     delete temp;
//                     temp = nullptr;
//                 }
//             }

//         protected:
//             std::string substring(const std::string& data, size_t index) {
//                 if (index != std::string::npos) 
//                     return data.substr(index);
                
//                 SimpleLogger::Warn("Target index was not found.", LogHandler::FILE);
//                 return "";
//             }

//             bool contains(const std::string& data, std::string_view target) {
//                 return data.find(target) != std::string::npos;
//             }

//             std::string substringByIndex(const Dataset& dataset, Criteria criteria, size_t& index) {
//                 auto [id, text, title, subject, date] = dataset; 
//                 std::string new_string;

//                 switch (criteria) {
//                     case Criteria::TEXT:
//                         new_string = substring(text, index);
//                         break;
//                     case Criteria::TITLE:
//                         new_string = substring(title, index);
//                         break;
//                     case Criteria::SUBJECT:
//                         new_string = substring(subject, index);
//                         break;
//                     case Criteria::DATE:
//                         new_string = substring(date, index);
//                         break;
//                 }

//                 return new_string;
//             } 

//             void split() {

//             }

//             size_t findTargetIndex(const Dataset& dataset, Criteria criteria, std::string_view target) {
//                 auto [id, text, title, subject, date] = dataset; 
//                 size_t index;

//                 switch (criteria) {
//                     case Criteria::TEXT:
//                         index = text.find(target); 
//                         break;
//                     case Criteria::TITLE:
//                         index = title.find(target); 
//                         break;
//                     case Criteria::SUBJECT:
//                         index = subject.find(target); 
//                         break;
//                     case Criteria::DATE:
//                         index = date.find(target); 
//                         break;
//                 }

//                 return index;
//             }

//             void traverse() {
//                 LinkedListNode* temp = head;
//                 while (temp != nullptr) {
//                     temp = temp->next;
//                 }
//             }

//             void isHeadEmpty() {
//                 if (head == nullptr) {
//                     SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
//                     return;
//                 }
//             }

//             void isHeadOrNextEmpty() {
//                 if (head == nullptr || head->next == nullptr) {
//                     SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
//                     return;
//                 }
//             }

//             size_t getSize() {
//                 return this->length;
//             }

//             // Helper function to split the linked list into two halves
//             LinkedListNode* getMiddle(LinkedListNode* temp) {
//                 if (temp == nullptr) {
//                     // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
//                     return temp;
//                 }

//                 LinkedListNode* first_half = temp;
//                 LinkedListNode* second_half = temp->next;
                
//                 // Iterate until second_half reaches the end of node, by then first_half will be the middle node
//                 while (second_half && second_half->next) {
//                     first_half = first_half->next;
//                     second_half = second_half->next->next;
//                 }

//                 return first_half; // first_half is the middle node
//             }

//             // Helper function to merge two sorted linked lists 
//                 LinkedListNode* merge(LinkedListNode* left, LinkedListNode* right) {
//                     LinkedListNode* dummy = new LinkedListNode({}); // Dummy node to simplify the merge process
//                     LinkedListNode* tail = dummy;
    
//                     DateUtility date_utility{};
//                     int32_t left_year = date_utility.getYear(left->data.date);
//                     int32_t right_year = date_utility.getYear(right->data.date);
                
//                     while (left != nullptr && right != nullptr) {
//                         if (left_year <= right_year) {
//                             tail->next = left;
//                             left = left->next;
//                         } else {
//                             tail->next = right;
//                             right = right->next;
//                         }

//                         tail = tail->next;
//                     }

//                     // Attach the remaining elements
//                     if (left != nullptr) {
//                         tail->next = left;
//                     } else {
//                         tail->next = right;
//                     }

//                     LinkedListNode* merged_head = dummy->next;
                    
//                     delete dummy;
//                     dummy = nullptr;
                    
//                     return merged_head;
                
//                 // if (left == nullptr)
//                 //     return right;
//                 // if (right == nullptr)
//                 //     return left;

//                 // DateUtility date_utility{};
//                 // int32_t left_year = date_utility.getYear(left->data.date);
//                 // int32_t right_year = date_utility.getYear(right->data.date);
                
//                 // // auto [left_day, left_month, left_year] = date.parseDate(left->data.date);
//                 // // auto [right_day, right_month, right_year] = date.parseDate(right->data.date);

//                 // // Recursively merge into one sorted linked list, using year from date
//                 // if (left_year <= right_year) {
//                 //     left->next = merge(left->next, right);
//                 //     return left;
//                 // } else {
//                 //     right->next = merge(left, right->next);
//                 //     return right;
//                 // }

//                 // if (left->data < right->data) {
//                 //     left->next = merge(left->next, right);
//                 //     return left;
//                 // } else {
//                 //     right->next = merge(left, right->next);
//                 //     return right;
//                 // }
//             }

//             // Applies merge sort recursively 
//             LinkedListNode* mergeSort(LinkedListNode* temp) {                
//                 // List is already sorted if list is empty
//                 if (temp == nullptr || temp->next == nullptr) {
//                     // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
//                     return temp;
//                 }

//                 // Get the middle of list
//                 LinkedListNode* middle = getMiddle(temp);
//                 LinkedListNode* second_half = middle->next;

//                 // Split the list into two halves
//                 middle->next = nullptr;

//                 // Recursive sort
//                 LinkedListNode* left = mergeSort(temp);
//                 LinkedListNode* right = mergeSort(second_half);

//                 // Merge the sorted halves
//                 return merge(left, right);
//             }


//             // ~LinkedList() {
//             //     LinkedListNode* current = head;

//             //     while (head != nullptr) {
//             //         LinkedListNode* temp = current;
//             //         current = current->next;
                    
//             //         delete temp;
//             //         temp = nullptr;
//             //     }
//             // }

//         private:
//             LinkedListNode* head = nullptr;
//             size_t length;
//     };
// } // namespace PerformanceEvaluation


//             // void containAnd(Dataset Dataset, Criteria criteria, std::string_view target) {
//             //     auto [text, title, subject, date] = Dataset; 
//             //     std::string new_string;
                
//             //     switch (criteria) {
//             //         case Criteria::TEXT:
//             //             break; 
//             //         case Criteria::TITLE:
//             //             break; 
//             //         case Criteria::SUBJECT:
//             //             break; 
//             //         case Criteria::DATE:
//             //             break; 
//             //     }
                
//                 // std::size_t index = findTargetIndex(Dataset, criteria, target);
                
//                 // if (substringByIndex(Dataset, criteria, index) {
//                 // }
                
//                 // return (findTargetIndex(Dataset, criteria, index, target) != std::string::npos) ? 
//                 //     substringByIndex(Dataset, criteria, index) : "";
//             // }
