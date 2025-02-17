

#include <iostream>
#include <fstream>
#include <string>
#include "SimpleLogger.h"
#include "Array.h"

namespace PerformanceEvaluation
{

    // Iterator support
    // Dataset *Array::begin()
    // {
    //     return m_Array;
    // }

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

    size_t Array::getLength() const
    {
        return m_Size;
    }

    void Array::insertEnd(const Dataset &dataset)
    {
        if (m_Size < MAX_SIZE)
        {
            m_Array[m_Size++] = dataset;
        }
        else
        {
            std::cerr << "Array is full. Cannot insert more items.\n";
        }
    }

    void Array::displayTitle() const
    {
        if (m_Size == 0)
        {
            std::cout << "Array is empty.\n";
            return;
        }

        std::cout << "TITLE\n-----------\n";

        for (size_t i = 0; i < m_Size; ++i)
        {
            std::cout << "ID:" << m_Array[i].id << "\n";
            // SimpleLogger::Info(m_Array[i].title, LogHandler::FILE);
            std::cout << "Title:" << m_Array[i].title << "\n";
        }

        std::cout << "\n";
    }

    void Array::displayText() const
    {
        if (m_Size == 0)
        {
            std::cout << "Array is empty.\n";
            return;
        }

        std::cout << "TEXT\n-----------\n";

        for (size_t i = 0; i < m_Size; ++i)
        {
            std::cout << m_Array[i].text << "\n";
        }

        std::cout << "\n";
    }

    void Array::displaySubject() const
    {
        if (m_Size == 0)
        {
            std::cout << "Array is empty.\n";
            return;
        }

        std::cout << "SUBJECT\n-----------\n";

        for (size_t i = 0; i < m_Size; ++i)
        {
            std::cout << m_Array[i].subject << "\n";
        }

        std::cout << "\n";
    }

    void Array::displayDate() const
    {
        if (m_Size == 0)
        {
            std::cout << "Array is empty.\n";
            return;
        }

        std::cout << "DATE\n-----------\n";

        for (size_t i = 0; i < m_Size; ++i)
        {
            SimpleLogger::Info(m_Array[i].date, LogHandler::FILE);
            // std::cout << m_Array[i].date << "\n";
        }

        std::cout << "\n";
    }

    void Array::clear()
    {
        m_Size = 0;
    }

    void Array::deleteElement(const Dataset &dataset)
    {
        for (size_t i = 0; i < m_Size; ++i)
        {
            if (m_Array[i].id == dataset.id)
            {
                for (size_t j = i; j < m_Size - 1; ++j)
                {
                    m_Array[j] = m_Array[j + 1];
                }
                --m_Size;
                return;
            }
        }
        std::cerr << "Element not found.\n";
    }

    void Array::displayFirst(int32_t count) const
    {
        if (m_Size == 0)
        {
            std::cout << "Array is empty.\n";
            return;
        }

        if (count > static_cast<int32_t>(m_Size))
        {
            count = static_cast<int32_t>(m_Size); // Limit count to available elements
        }

        for (int32_t i = 0; i < count; ++i)
        {
            const auto &item = m_Array[i];
            std::cout << "ID: " << item.id << "\n"
                      << "TITLE: " << item.title << "\n"
                      << "TEXT: " << item.text << "\n"
                      << "SUBJECT: " << item.subject << "\n"
                      << "DATE: " << item.date << "\n"
                      << "-----------\n";
        }
        // SimpleLogger::Info("Success!", LogHandler::CONSOLE);
    }

    void Array::displayAll() const
    {
        if (m_Size == 0)
        {
            std::cout << "Array is empty.\n";
            return;
        }

        for (size_t i = 0; i < m_Size; ++i)
        {
            const auto &item = m_Array[i];
            std::cout << "ID: " << item.id << "\n"
                      << "TITLE: " << item.title << "\n"
                      << "TEXT: " << item.text << "\n"
                      << "SUBJECT: " << item.subject << "\n"
                      << "DATE: " << item.date << "\n"
                      << "-----------\n";
        }
        // SimpleLogger::Info("Success!", LogHandler::CONSOLE);
    }
};