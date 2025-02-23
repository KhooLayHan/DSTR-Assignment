#pragma once

#include <iostream>
#include <functional>
#include <cassert>

#include "DynamicArray.h"
#include "Buckets.h"

namespace PerformanceEvaluation {

    template <typename K, typename V>
    class HashMap {
    private:
        DynamicArray<Buckets<K, V>> m_Buckets;
        std::hash<K> m_HashFunction;
        size_t m_BucketCount;
        size_t m_Size;
    
    public:
        constexpr explicit HashMap(size_t capacity = 1000) noexcept : m_Buckets(capacity), m_BucketCount(capacity), m_Size(0) {}
        
        constexpr void Insert(const K& key, const V& value) noexcept {
            size_t index = m_HashFunction(key) % m_BucketCount;
            BucketNode<K, V>* existing = m_Buckets[index].Find(key);
            if (existing) {
                existing->m_Value = value;
            } else {
                m_Buckets[index].Insert(key, value);
                ++m_Size;
            }
        }
        
        constexpr bool Remove(const K& key) noexcept {
            size_t index = m_HashFunction(key) % m_BucketCount;
            if (m_Buckets[index].Remove(key)) {
                --m_Size;
                return true;
            }
            return false;
        }
        
        [[nodiscard]] constexpr V* Find(const K& key) noexcept {
            size_t index = m_HashFunction(key) % m_BucketCount;
            BucketNode<K, V>* node = m_Buckets[index].Find(key);
            return node ? &node->m_Value : nullptr;
        }
        
        [[nodiscard]] constexpr V* Find(const K& key) const noexcept {
            size_t index = m_HashFunction(key) % m_BucketCount;
            BucketNode<K, V>* node = m_Buckets[index].Find(key);
            return node ? &node->m_Value : nullptr;
        }
        
        constexpr void Clear() noexcept {
            for (size_t i = 0; i < m_BucketCount; ++i) {
                m_Buckets[i].Clear();
            }
            m_Size = 0;
        }
        
        constexpr void PrintAll() noexcept {
            for (size_t i = 0; i < m_BucketCount; ++i) {
                std::cout << "BUCKET" << i << ": \n";
                for (auto it = m_Buckets[i].begin(); it != m_Buckets[i].end(); ++it) {
                    std::cout << "{ " << it->first << ": " << it->second << " }\n";
                }
                std::cout << "\n";
            }
        }
             
        constexpr V& operator[](const K& key) noexcept {
            size_t index = m_HashFunction(key) % m_BucketCount;
            BucketNode<K, V>* existing = m_Buckets[index].Find(key);
            if (existing) {
                return existing->m_Value;
            }
            m_Buckets[index].Insert(key, V());
            return m_Buckets[index].Find(key)->m_Value;
        }
        
        [[nodiscard]] constexpr bool Contains(const K& key) noexcept {
            size_t index = m_HashFunction(key) % m_BucketCount;
            return m_Buckets[index].Find(key) != nullptr;
        }
        
        [[nodiscard]] constexpr size_t Size() const noexcept { return m_Size; }
        [[nodiscard]] constexpr bool Empty() const noexcept { return m_Size == 0; }
        [[nodiscard]] constexpr size_t BucketCount() const noexcept { return m_BucketCount; }
        
        constexpr void Rehash(size_t new_bucket_count) noexcept {
            DynamicArray<Buckets<K, V>> new_buckets(new_bucket_count);
            for (size_t i = 0; i < m_BucketCount; ++i) {
                for (auto it = m_Buckets[i].begin(); it != m_Buckets[i].end(); ++it) {
                    size_t new_index = m_HashFunction(it->first) % new_bucket_count;
                    new_buckets[new_index].Insert(it->first, it->second);
                }
            }
            m_Buckets = std::move(new_buckets);
            m_BucketCount = new_bucket_count;
        }
        
        constexpr void Reserve(size_t new_capacity) noexcept {
            if (new_capacity > m_BucketCount) {
                Rehash(new_capacity);
            }
        }

        [[nodiscard]] constexpr V& Get(const K& key) {
            size_t index = m_HashFunction(key) % m_BucketCount;
            BucketNode<K, V>* node = m_Buckets[index].Find(key);
            if (!node) {
                throw std::out_of_range("Key not found in HashMap");
            }
            return node->m_Value;
        }

        class Iterator {
        private:
            DynamicArray<Buckets<K, V>>& m_Buckets;
            size_t m_BucketIndex;
            BucketNode<K, V>* m_Current;
        
        public:
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::forward_iterator_tag;
        
            constexpr Iterator(DynamicArray<Buckets<K, V>>& buckets, size_t index) noexcept 
                : m_Buckets(buckets), m_BucketIndex(index), m_Current(nullptr) {
                while (m_BucketIndex < m_Buckets.GetLength() && !m_Buckets[m_BucketIndex].GetHead()) {
                    ++m_BucketIndex;
                }
                if (m_BucketIndex < m_Buckets.GetLength()) {
                    m_Current = m_Buckets[m_BucketIndex].GetHead();
                }
            }
        
            constexpr bool operator!=(const Iterator& other) const noexcept {
                return m_BucketIndex != other.m_BucketIndex || m_Current != other.m_Current;
            }
        
            constexpr bool operator==(const Iterator& other) const noexcept {
                return m_BucketIndex == other.m_BucketIndex && m_Current == other.m_Current;
            }

            constexpr std::pair<K, V> operator*() const noexcept {
                return {m_Current->m_Key, m_Current->m_Value};
            }
        
            constexpr Iterator& operator++() noexcept {
                if (m_Current) m_Current = m_Current->m_Next;
                while (!m_Current && ++m_BucketIndex < m_Buckets.GetLength()) {
                    m_Current = m_Buckets[m_BucketIndex].GetHead();
                }
                return *this;
            }
        
            constexpr Iterator operator++(int) noexcept {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }
        };
        
        [[nodiscard]] constexpr Iterator begin() noexcept { return Iterator(m_Buckets, 0); }
        [[nodiscard]] constexpr Iterator end() noexcept { return Iterator(m_Buckets, m_Buckets.GetLength()); }
    };
}
