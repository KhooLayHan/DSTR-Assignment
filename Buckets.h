#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace PerformanceEvaluation
{   
    template <typename Key, typename Value>
    struct BucketNode {
        Key m_Key;
        Value m_Value;
        
        BucketNode* m_Next;
        BucketNode* m_Previous;
        
        BucketNode(Key key, Value value) 
            : m_Key(std::move(key)), m_Value(std::move(value)), m_Previous(nullptr), m_Next(nullptr) {
            
        } 
    };

    // Doubly Linked List implementation to store key-value pairs and is used for HashMap  
    template <typename Key, typename Value>
    class Buckets {
        public:
            Buckets() : m_Head(nullptr), m_Tail(nullptr) {

            }

            void Insert(const Key& key, const Value& value) {
                BucketNode<Key, Value>* existing = Find(key);

                if (existing) {
                    existing->m_Value = value; // Update existing key
                    return;
                }

                BucketNode<Key, Value>* node = new BucketNode<Key, Value>(key, value);

                if (!m_Head) {
                    m_Head = node;
                    m_Tail = node; 
                } else {
                    m_Tail->m_Next = node;
                    node->m_Previous = m_Tail;
                    m_Tail = node;
                }
            }

            BucketNode<Key, Value>* Find(const Key& key) const {
                BucketNode<Key, Value>* temp = m_Head;

                while (temp) {
                    if (temp->m_Key == key)
                        return temp;
                    
                    temp = temp->m_Next;
                }

                return nullptr;
            }

            // void Display() {
            //     BucketNode<Key, Value>* temp = m_Head;

            //     while (temp) {
            //         std::cout << "[" << temp->m_Key << ": " << temp->m_Value << "] <-> ";
            //         temp = temp->m_Next;
            //     }

            //     std::cout << "NULL\n";
            // }

            void Clear() {
                BucketNode<Key, Value>* temp = m_Head;
                
                while (temp) {
                    BucketNode<Key, Value>* next = temp->m_Next;

                    delete temp;
                    temp = next;
                }

                m_Head = nullptr;
                m_Tail = nullptr;
            }

            BucketNode<Key, Value>* GetHead() const {
                return m_Head;
            }

            ~Buckets() {
                Clear();
            }
        private:
            BucketNode<Key, Value>* m_Head;
            BucketNode<Key, Value>* m_Tail;
    };
} // namespace PerformanceEvaluation
