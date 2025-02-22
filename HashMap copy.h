// #pragma once

// #include <iostream>
// #include <string>

// #include "Buckets.h"
// #include "DynamicArray.h"

// #include "BucketsIterator.h"
// #include "HashMapIterator.h"

// namespace PerformanceEvaluation
// {
//     template <typename Key, typename Value>
//     class HashMap {
//         public:
//             HashMap(size_t bucket_count = 5) 
//                 : m_BucketCount(bucket_count), m_Buckets(bucket_count), m_Length(0) {
//                 for (size_t i = 0; i != m_BucketCount; i++) {
//                     m_Buckets.Insert(i, new Buckets<Key, Value>);
//                 }
//             }

//             Value& operator[](const Key& key) {
//                 int32_t index = HashFunction(key);

//                 if (!m_Buckets[index])
//                     m_Buckets[index] = new Buckets<Key, Value>;

//                 BucketNode<Key, Value>* found = m_Buckets[index]->Find(key);

//                 if (!found) {
//                     m_Buckets[index]->Insert(key, Value()); 
//                     found = m_Buckets[index]->Find(key);

//                     ++m_Length;
//                 }

//                 return found->m_Value;
//             }

//             bool Contains(const Key& key) const {
//                 return Count(key) > 0;
//             }

//             int32_t Count(const Key& key) const {
//                 int32_t index = HashFunction(key);
//                 return m_Buckets[index]->Find(key) ? 1 : 0;
//             }

//             Value* Find(const Key& key) {
//                 int32_t index = HashFunction(key);

//                 BucketNode<Key, Value>* found = m_Buckets[index]->Find(key);
//                 return found ? &found->m_Value : nullptr;
//             }

//             void Insert(const Key& key, const Value& value) {
//                 int32_t index = HashFunction(key);
                
//                 if (!m_Buckets[index]->Find(key)) {
//                     m_Buckets[index]->Insert(key, value);

//                     ++m_Length;
//                 }
//             }

//             void Emplace(Key key, Value value) {
//                 Insert(std::move(key), std::move(value));
//             }

//             void Clear() {
//                 for (size_t i = 0; i != m_BucketCount; i++) {
//                     m_Buckets[i]->Clear();
//                 }

//                 m_Length = 0;
//             }

//             size_t GetLength() const {
//                 return m_Length;
//             }

//             bool IsEmpty() const {
//                 return m_Length == 0;
//             }

//             size_t GetBucketCount() const {
//                 return m_BucketCount;
//             }

//             void Rehash(size_t bucket_count) {
//                 if (bucket_count <= m_BucketCount)  
//                     return;
                
//                 DynamicArray<Buckets<Key, Value>*> buckets(bucket_count, nullptr);

//                 for (size_t i = 0; i != bucket_count; i++) 
//                     buckets.Insert(i, new Buckets<Key, Value>);

//                 for (size_t i = 0; i != m_BucketCount; i++) {
//                     BucketNode<Key, Value>* temp = m_Buckets[i]->GetHead();

//                     while (temp) {
//                         size_t index = HashFunction(temp->m_Key, bucket_count);
//                         buckets[index]->Insert(temp->m_Key, temp->m_Value);

//                         temp = temp->m_Next;    
//                     }

//                     delete m_Buckets[i];
//                 }

//                 m_Buckets = std::move(buckets);
//                 m_BucketCount = bucket_count;
//             }

//             // int32_t Get(const std::string& key) {
//             //     int32_t index = HashFunction(key);

//             //     BucketNode* found_node = m_Buckets[index]->Find(key);

//             //     return found_node ? found_node->m_Value : -1; 
//             // }

//             void Display() const {
//                 for (size_t i = 0; i != m_BucketCount; i++) {
//                     std::cout << "Bucket " << i << ": ";
                    
//                     BucketNode<Key, Value>* temp = m_Buckets[i]->GetHead();

//                     while (temp) {
//                         std::cout << "[" << temp->m_Key << ": " << temp->m_Value << "] <-> ";
//                         temp = temp->m_Next;
//                     }

//                     std::cout << "NULL\n";
//                 }
//             }

//             // using Iterator = HashMapIterator<Key, Value>;

//             Iterator begin() { return Iterator(m_Buckets, m_BucketCount); }
//             Iterator end() { return Iterator(m_Buckets, m_BucketCount, m_BucketCount); }
            
//             ~HashMap() {
//                 for (size_t i = 0; i != m_BucketCount; i++) {
//                     delete m_Buckets[i];
//                 }
//             }
//         private:
//             int32_t HashFunction(const Key& key, size_t bucket_count = 0) const {
//                 int32_t hash = 0;
//                 size_t modulus = bucket_count ? bucket_count : m_BucketCount;

//                 for (char c : key)
//                     hash = (hash * 31 + c) % modulus;
                
//                 return hash;
//             }

//             size_t m_BucketCount;
//             Buckets<Key, Value>** m_Buckets;
//             size_t m_Length;
//     };
// } // namespace PerformanceEvaluation

// // class HashTable {
// //     public:
// //         class Iterator {
// //         public:
// //             Iterator(BucketNode* node, size_t bucketIndex, HashTable* table) 
// //                 : m_Current(node), m_BucketIndex(bucketIndex), m_Table(table) {
// //                 AdvanceToNextValid();
// //             }

// //             std::pair<std::string, int32_t> operator*() const {
// //                 return {m_Current->m_Key, m_Current->m_Value};
// //             }

// //             Iterator& operator++() {
// //                 if (m_Current) m_Current = m_Current->m_Next;
// //                 AdvanceToNextValid();
// //                 return *this;
// //             }

// //             bool operator!=(const Iterator& other) const {
// //                 return m_Current != other.m_Current;
// //             }
        
// //         private:
// //             void AdvanceToNextValid() {
// //                 while (!m_Current && m_BucketIndex < m_Table->m_BucketCount - 1) {
// //                     m_BucketIndex++;
// //                     m_Current = m_Table->m_Buckets[m_BucketIndex]->Head();
// //                 }
// //             }

// //             BucketNode* m_Current;
// //             size_t m_BucketIndex;
// //             HashTable* m_Table;
// //         };

// //         HashTable(size_t length = 5) : m_BucketCount(length), m_Buckets(length) {
// //             for (size_t i = 0; i != m_BucketCount; i++) {
// //                 m_Buckets.Insert(i, new Buckets);
// //             }
// //         }

// //         void Insert(const std::string& key, int32_t value) {
// //             int32_t index = HashFunction(key);
// //             m_Buckets[index]->Insert(key, value);
// //         }

// //         int32_t Get(const std::string& key) {
// //             int32_t index = HashFunction(key);
// //             BucketNode* found_node = m_Buckets[index]->Find(key);
// //             return found_node ? found_node->m_Value : -1; 
// //         }

// //         void Display() {
// //             for (size_t i = 0; i != m_BucketCount; i++) {
// //                 std::cout << "Bucket " << i << ": ";
// //                 m_Buckets[i]->Display();
// //             }
// //         }

// //         Iterator begin() {
// //             return Iterator(nullptr, 0, this);
// //         }

// //         Iterator end() {
// //             return Iterator(nullptr, m_BucketCount, this);
// //         }

// //         ~HashTable() {
// //             for (size_t i = 0; i != m_BucketCount; i++) 
// //                 delete m_Buckets[i];
// //         }
    
// //     private:
// //         int32_t HashFunction(const std::string& key) {
// //             int32_t hash = 0;
// //             for (char c : key)
// //                 hash = (hash * 31 + c) % m_BucketCount;
// //             return hash;
// //         }

// //         DynamicArray<Buckets*> m_Buckets;
// //         size_t m_BucketCount;
// // };
