#pragma once

#include <iostream>
#include <string>

#include "DynamicArray.h"
#include "Buckets.h"

namespace PerformanceEvaluation
{
    template <typename Key, typename Value>
    class HashTable {
        public:
            HashTable(size_t bucket_count = 5) 
                : m_BucketCount(bucket_count), m_Buckets(bucket_count), m_ {
                for (size_t i = 0; i != m_BucketCount; i++) {
                    m_Buckets.Insert(i, new Buckets<Key, Value>);
                }
            }

            void Insert(const std::string& key, int32_t value) {
                int32_t index = HashFunction(key);
                m_Buckets[index]->Insert(key, value);
            }

            int32_t Get(const std::string& key) {
                int32_t index = HashFunction(key);

                BucketNode* found_node = m_Buckets[index]->Find(key);

                return found_node ? found_node->m_Value : -1; 
            }

            void Display() {
                for (size_t i = 0; i != m_BucketCount; i++) {
                    std::cout << "Bucket " << i << ": ";
                    m_Buckets[i]->Display();
                }
            }

            ~HashTable() {
                for (size_t i = 0; i != m_BucketCount; i++) 
                    delete m_Buckets[i];
            }
        private:
            int32_t HashFunction(const std::string& key) {
                int32_t hash = 0;

                for (char c : key)
                    hash = (hash * 31 + c) % m_BucketCount;
                
                return hash;
            }

            DynamicArray<Buckets*> m_Buckets;
            size_t m_BucketCount;
    };
} // namespace PerformanceEvaluation

// class HashTable {
//     public:
//         class Iterator {
//         public:
//             Iterator(BucketNode* node, size_t bucketIndex, HashTable* table) 
//                 : m_Current(node), m_BucketIndex(bucketIndex), m_Table(table) {
//                 AdvanceToNextValid();
//             }

//             std::pair<std::string, int32_t> operator*() const {
//                 return {m_Current->m_Key, m_Current->m_Value};
//             }

//             Iterator& operator++() {
//                 if (m_Current) m_Current = m_Current->m_Next;
//                 AdvanceToNextValid();
//                 return *this;
//             }

//             bool operator!=(const Iterator& other) const {
//                 return m_Current != other.m_Current;
//             }
        
//         private:
//             void AdvanceToNextValid() {
//                 while (!m_Current && m_BucketIndex < m_Table->m_BucketCount - 1) {
//                     m_BucketIndex++;
//                     m_Current = m_Table->m_Buckets[m_BucketIndex]->Head();
//                 }
//             }

//             BucketNode* m_Current;
//             size_t m_BucketIndex;
//             HashTable* m_Table;
//         };

//         HashTable(size_t length = 5) : m_BucketCount(length), m_Buckets(length) {
//             for (size_t i = 0; i != m_BucketCount; i++) {
//                 m_Buckets.Insert(i, new Buckets);
//             }
//         }

//         void Insert(const std::string& key, int32_t value) {
//             int32_t index = HashFunction(key);
//             m_Buckets[index]->Insert(key, value);
//         }

//         int32_t Get(const std::string& key) {
//             int32_t index = HashFunction(key);
//             BucketNode* found_node = m_Buckets[index]->Find(key);
//             return found_node ? found_node->m_Value : -1; 
//         }

//         void Display() {
//             for (size_t i = 0; i != m_BucketCount; i++) {
//                 std::cout << "Bucket " << i << ": ";
//                 m_Buckets[i]->Display();
//             }
//         }

//         Iterator begin() {
//             return Iterator(nullptr, 0, this);
//         }

//         Iterator end() {
//             return Iterator(nullptr, m_BucketCount, this);
//         }

//         ~HashTable() {
//             for (size_t i = 0; i != m_BucketCount; i++) 
//                 delete m_Buckets[i];
//         }
    
//     private:
//         int32_t HashFunction(const std::string& key) {
//             int32_t hash = 0;
//             for (char c : key)
//                 hash = (hash * 31 + c) % m_BucketCount;
//             return hash;
//         }

//         DynamicArray<Buckets*> m_Buckets;
//         size_t m_BucketCount;
// };
