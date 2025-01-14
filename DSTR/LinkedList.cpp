#include <iostream>
#include <string>

namespace PerformanceEvaluation {
    
    // Implement a Node structure
    template <typename T>
    struct LinkedListNode {
        T data;
        LinkedListNode* next;

        LinkedListNode(T value) 
            : data(value), next(nullptr) {

        }
    };
    
    // Implement the Linked List class
    template <typename T>
    class LinkedList {
        public:
            LinkedList() 
                : head(nullptr) {

            }
        
            // LinkedList
            void addBegin(T value) {
                LinkedListNode<T>* node = new LinkedListNode(value);
                node->next = head;
                head = node;
            }
            
            void addEnd(T value) {
                LinkedListNode<T>* node = new LinkedListNode(value);

                if (head == nullptr) {
                    head = node;
                    return;
                }

                LinkedListNode<T>* temp = head;
                
                while (temp->next != nullptr) {
                    temp = temp->next;
                }

                temp->next = node;
            }

            void deleteNode(T value) {
                if (head == nullptr) {
                    std::cerr << "List is empty.\n";
                    return;
                }

                if (head->data == value) {
                    LinkedListNode<T>* temp = head;
                    head = head->next;
                    delete temp;
                    return;
                }

                LinkedListNode<T>* temp = head;
                
                while (temp->next != nullptr && temp->next->data != value) {
                    temp = temp->next;
                }

                if (temp->next == nullptr) {
                    std::cerr << "Value cannot be found in the list.\n";
                }

                // Node to be deleted
                LinkedListNode<T>* node = temp->next;
                temp->next = temp->next->next;
                delete node;
            }

            void display() {
                if (head == nullptr) {
                    std::cerr << "List is empty.\n";
                    return;
                }

                LinkedListNode<T>* temp = head;

                while (temp != nullptr) {
                    std::cout << temp->data << "\n";
                    temp = temp->next;
                } 
            }

            ~LinkedList() {
                LinkedListNode<T>* temp;

                while (head != nullptr) {
                    temp = head;
                    head = head->next;
                    
                    delete temp;
                }
            }

        private:
            LinkedListNode<T>* head;
    };
} // namespace PerformanceEvaluation
