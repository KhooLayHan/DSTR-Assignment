#include "Array.h"

namespace PerformanceEvaluation {

    // template <typename T, size_t Length>
    // void Array<T, Length>::DisplayFirst(int32_t count) const {
    //     if (m_Size == 0) {
    //         std::cout << "Array is empty.\n";
    //         return;
    //     }

    //     int32_t limit = (count > m_Size) ? m_Size : count; // Ensure we don't exceed the stored elements

    //     for (int32_t i = 0; i < limit; i++) {
    //         std::cout << "\033[34;1m[" << i + 1 << "]:\033[0m " << m_Data[i] << "\n";
    //     }

    //     std::cout << std::endl;
    // }

    // template <typename T, size_t Length>
    // void Array<T, Length>::InsertEnd(const T& value) {
    //     if (m_Size < Length) {
    //         m_Data[m_Size++] = value;
    //     } else {
    //         std::cerr << "Array is full. Cannot insert more elements." << std::endl;
    //     }
    // }

    template <typename T, size_t Length>
    void Array<T, Length>::DeleteElement(const T& value) {
        for (size_t i = 0; i < m_Size; i++) {
            if (m_Data[i] == value) {
                // Shift elements left
                for (size_t j = i; j < m_Size - 1; j++) {
                    m_Data[j] = m_Data[j + 1];
                }
                m_Size--;
                return;
            }
        }
        std::cerr << "Element not found in array." << std::endl;
    }
} // namespace PerformanceEvaluation