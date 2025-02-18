#pragma once

#include <cassert>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <utility>

namespace PerformanceEvaluation
{
    template <typename T>
    class Vector {
        public:
            Vector() : m_Length(0), m_Capacity(1) {
                m_Data = new T[m_Capacity];
            }

            Vector(std::initializer_list<T> init_list)
                : m_Length(init_list.size()), m_Capacity(init_list.size()) {
                m_Data = new T[m_Capacity];

                size_t i = 0;
                for (const auto& item : init_list) {
                    m_Data[i++] = item;
                }
            }

            ~Vector() {
                delete[] m_Data;
            }

            // Copy constructors
            Vector(const Vector& other) : m_Length(other.m_Length), m_Capacity(other.m_Capacity) noexcept {
                m_Data = new T[m_Capacity];

                for (size_t i = 0; i != m_Length; i++) {
                    m_Data[i] = other.m_Data[i];
                }
            } 

            // Move constructors
            Vector(Vector&& other) : m_Data(other.m_Data), m_Length(other.m_Length), m_Capacity(other.m_Capacity) noexcept {
                other.m_Data = nullptr;
                other.m_Length = 0;
                other.m_Capacity = 0;
            } 

            const Vector(Vector&& other) : m_Data(other.m_Data), m_Length(other.m_Length), m_Capacity(other.m_Capacity) const noexcept {
                other.m_Data = nullptr;
                other.m_Length = 0;
                other.m_Capacity = 0;
            } 

            // Copy assignment
            constexpr Vector& operator=(const Vector& other) noexcept {
                if (this != &other) { // Self-assignment check
                    delete[] m_Data; // Free current memory
                    
                    m_Length = other.m_Length;
                    m_Capacity = other.m_Capacity;
                    m_Data = new T[m_Capacity];
                    
                    for (size_t i = 0; i != m_Length; i++) 
                        m_Data[i] = other.m_Data[i];
                }

                return *this;
            }

            constexpr const Vector& operator=(const Vector& other) const noexcept {
                if (this != &other) { // Self-assignment check
                    delete[] m_Data; // Free current memory
                    
                    m_Length = other.m_Length;
                    m_Capacity = other.m_Capacity;
                    m_Data = new T[m_Capacity];
                    
                    for (size_t i = 0; i != m_Length; i++) 
                        m_Data[i] = other.m_Data[i];
                }
                
                return *this;
            }

            // Move assignment
            constexpr Vector& operator=(T&& other) noexcept {
                if (this != &other) { // Self-assignment check
                    delete[] m_Data; // Free current memory
                    
                    m_Length = other.m_Length;
                    m_Capacity = other.m_Capacity;
                    m_Data = new T[m_Capacity];
                    
                    other.m_Data = nullptr; // Null the other vector's data
                    other.m_Length = 0; 
                    other.m_Capacity = 0; 
                }
                
                return *this;
            }

            constexpr const Vector& operator=(T&& other) const noexcept {
                if (this != &other) { // Self-assignment check
                    delete[] m_Data; // Free current memory
                    
                    m_Length = other.m_Length;
                    m_Capacity = other.m_Capacity;
                    m_Data = new T[m_Capacity];
                    
                    other.m_Data = nullptr; // Null the other vector's data
                    other.m_Length = 0; 
                    other.m_Capacity = 0; 
                }
                
                return *this;
            }

            // Overloading [] operator
            constexpr T& operator[](size_t index) noexcept {
                assert(index < m_Length && "Index specified is out of bounds!");

                return m_Data[index];
            }
            
            constexpr const T& operator[](size_t index) const noexcept {
                assert(index < m_Length && "Index specified is out of bounds!");

                return m_Data[index];
            }

            void Clear() const noexcept {
                m_Length = 0;
            }
            
            constexpr bool IsEmpty() const noexcept {
                return m_Length == 0;
            }

            constexpr size_t GetCapacity() const noexcept {
                return m_Capacity;
            } 

            constexpr size_t GetLength() const noexcept {
                return m_Length;
            } 

            void PushBack(const T& value) {
                if (m_Length == m_Capacity)
                    Resize(m_Capacity * 2);

                m_Data[m_Length] = value;
                m_Length++;
            }

            template <typename... Args>
            void EmplaceBack(Args&&... args) {
                if (m_Length == m_Capacity)
                    Resize(m_Capacity * 2);

                // Constructs the elements in place at the end of the vector
                ::new(&m_Data[m_Length]) T(std::forward<Args>(args)...);

                m_Length++;
            }

            void PopBack() noexcept {
                if (m_Length > 0)
                    m_Length--;
            }
            
            void Reserve(size_t capacity) {
                if (capacity > m_Capacity)
                    Resize(capacity);
            }

            void Resize(size_t capacity) {
                assert(capacity > m_Length && "New capacity must be greater than current length!");

                T* data = new T[capacity];

                for (size_t i = 0; i != m_Length; i++) {
                    data[i] = std::move(m_Data[i]);
                }

                delete[] m_Data;

                m_Data = data;
                m_Capacity = capacity;
            }

            constexpr T* GetData() noexcept {
                return m_Data;
            } 

            constexpr const T* GetData() const noexcept {
                return m_Data;
            } 

            struct Iterator {
                T* m_Pointer;

                Iterator(T* pointer) : m_Pointer(pointer) {

                }

                T& operator*() {
                    return *m_Pointer;
                }

                T* operator->() {
                    return m_Pointer;
                }

                Iterator& operator++(size_t) {
                    Iterator temp = *this;
                    ++(*this);

                    return temp;
                }

                constexpr bool operator!=(const Iterator& other) const noexcept {
                    return m_Pointer != other.m_Pointer;
                } 
            };

            Iterator Begin() noexcept {
                return Iterator(m_Data);
            }

            Iterator End() noexcept {
                return Iterator(m_Data + m_Length);
            }
            
            const Iterator Begin() const noexcept {
                return Iterator(m_Data);
            }

            const Iterator End() const noexcept {
                return Iterator(m_Data + m_Length);
            }
        private:
            T* m_Data;
            size_t m_Length;
            size_t m_Capacity; 
    };    
} // namespace PerformanceEvaluation
