

#include <iostream>
#include <fstream>
#include <string>
#include "SimpleLogger.h"
#include "Array.h"
#include "SimpleFileLogger.h"
#include "SimpleConsoleLogger.h"
#include "SimpleLoggingService.h"

namespace PerformanceEvaluation {

    // Iterator support
    Dataset *Array::begin()
    {
        return m_Array;
    }

    Dataset *Array::end()
    {
        return m_Array + m_Size;
    }

    const Dataset *Array::begin() const
    {
        return m_Array;
    }

    const Dataset *Array::end() const
    {
        return m_Array + m_Size;
    }

    size_t Array::getLength() const {
        return m_Size;
    }

    void Array::insertEnd(const Dataset& dataset) {
        if (m_Size < MAX_SIZE) {
            m_Array[m_Size++] = dataset;
        } else {
            std::cerr << "Array is full. Cannot insert more items.\n";
        }
    }
    
    void Array::displayTitle() const {
        if (m_Size == 0) {
            std::cout << "Array is empty.\n";
            return;
        }
    
        std::cout << "TITLE\n-----------\n";
    
        for (size_t i = 0; i < m_Size; ++i) {
            std::cout << "ID:" << m_Array[i].m_Id << "\n"; 
            //SimpleLogger::Info(m_Array[i].title, LogHandler::FILE);
            std::cout << "Title:" << m_Array[i].m_Title << "\n";  
        }
    
        std::cout << "\n";
    }

    void Array::displayText() const {
        if (m_Size == 0) {
            std::cout << "Array is empty.\n";
            return;
        }
    
        std::cout << "TEXT\n-----------\n";
    
        for (size_t i = 0; i < m_Size; ++i) {
            std::cout << m_Array[i].m_Text << "\n";
        }
    
        std::cout << "\n";
    }

    void Array::displaySubject() const {
        if (m_Size == 0) {
            std::cout << "Array is empty.\n";
            return;
        }
    
        std::cout << "SUBJECT\n-----------\n";
    
        for (size_t i = 0; i < m_Size; ++i) {
            std::cout << m_Array[i].m_Subject << "\n";
        }
    
        std::cout << "\n";
    }

    void Array::displayDate() const {
        if (m_Size == 0) {
            std::cout << "Array is empty.\n";
            return;
        }
    
        std::cout << "DATE\n-----------\n";
    
        for (size_t i = 0; i < m_Size; ++i) {
            // SimpleLogger::Info(m_Array[i].m_Date, LogHandler::FILE);

            SimpleConsoleLogger console;
            SimpleLoggingService::UseDebugLogger(console, m_Array[i].m_Date); 
            // std::cout <  < m_Array[i].date << "\n";
        }
    
        std::cout << "\n";
    }    

    void Array::clear() {
        m_Size = 0;
    }

    size_t Array::getSize() const {
        return m_Size;
    }

    void Array::displayLength(std::string_view file_path) const {
        std::cout << "The total number of articles from the " << file_path << " dataset is "
            << getSize() << ".\n";
    }

    // Retrieves an element at a given index
    Dataset Array::getElement(size_t index) const {
        if (index >= m_Size) {
            throw std::out_of_range("Index out of range.");
        }
        return m_Array[index];
    }

    // Sets an element at a given index
    void Array::setElement(size_t index, const Dataset& dataset) {
        if (index >= m_Size) {
            throw std::out_of_range("Index out of range.");
        }
        m_Array[index] = dataset;
    }

    void Array::deleteElement(const Dataset& dataset) {
        for (size_t i = 0; i < m_Size; ++i) {
            if (m_Array[i].m_Id == dataset.m_Id) { 
                for (size_t j = i; j < m_Size - 1; ++j) {
                    m_Array[j] = m_Array[j + 1];
                }
                --m_Size;
                return;
            }
        }
        std::cerr << "Element not found.\n";
    }

    void Array::displayFirst(int32_t count) const {
        if (m_Size == 0) {
            std::cout << "Array is empty.\n";
            return;
        }
    
        if (count > static_cast<int32_t>(m_Size)) {
            count = static_cast<int32_t>(m_Size);  // Limit count to available elements
        }
    
        for (int32_t i = 0; i < count; ++i) {
            const auto& item = m_Array[i];
            std::cout << "\n\033[34;1mID:\033[0m "      << item.m_Id      << "\n"
                      << "\033[34;1mTITLE:\033[0m "   << item.m_Title   << "\n"
                      << "\033[34;1mTEXT:\033[0m "    << item.m_Text    << "\n"
                      << "\033[34;1mSUBJECT:\033[0m " << item.m_Subject << "\n"
                      << "\033[34;1mDATE:\033[0m "    << item.m_Date    << "\n"
                      << "-----------\n";
        }
    
        std::cout << "\n";
    }    

    void Array::displayAll() const {
        if (m_Size == 0) {
            std::cout << "Array is empty.\n";
            return;
        }
    
        for (size_t i = 0; i < m_Size; ++i) {
            const auto& item = m_Array[i];
            std::cout << "ID: "      << item.m_Id      << "\n"
                      << "TITLE: "   << item.m_Title   << "\n"
                      << "TEXT: "    << item.m_Text    << "\n"
                      << "SUBJECT: " << item.m_Subject << "\n"
                      << "DATE: "    << item.m_Date    << "\n"
                      << "-----------\n";
        }
        // SimpleLogger::Info("Success!", LogHandler::CONSOLE);
    }

    void Array::swap(size_t i, size_t j) {
        if (i >= m_Size || j >= m_Size) {
            throw std::out_of_range("Index out of range.");
        }
        // Swap the elements at the given indices
        Dataset temp = m_Array[i];
        m_Array[i] = m_Array[j];
        m_Array[j] = temp;
    }
};