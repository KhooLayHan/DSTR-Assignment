#pragma once 

#include <iostream>
#include <string>
#include <cctype>

#include "WordList.h"

namespace PerformanceEvaluation
{
    class WordTokenizer {
    public:
        WordTokenizer() : m_Iterator(m_Words.end()) {}

        explicit WordTokenizer(const std::string& text) : m_Iterator(m_Words.end()) {
            Tokenize(text);
            Reset();
        }

        bool HasNext() const {
            return m_Iterator != m_Words.end();
        }

        std::string Next() {
            if (!HasNext()) 
                throw std::out_of_range("No more words available");
            return *(m_Iterator++);  
        }

        void Reset() {
            if (m_Words.begin() != m_Words.end()) 
                m_Iterator = m_Words.begin();
            // else 
            //     m_Iterator = nullptr;
        }

    private:
        void Tokenize(const std::string& text) {
            size_t start = 0, end;
            
            while (start < text.size()) {
                while (start < text.size() && !IsWordCharacter(text[start])) {
                    start++;
                }
                if (start >= text.size()) break;

                end = start;
                while (end < text.size() && IsWordCharacter(text[end])) {
                    end++;
                }

                std::string word = text.substr(start, end - start);
                if (!word.empty()) {
                    m_Words.InsertEnd(word);  
                }

                start = end;
            }
        }

        static constexpr bool IsWordCharacter(char ch) {
            return std::isalnum(ch) || ch == '\'' || ch == '-' || ch == '.' || ch == '$';
        }

        WordList<std::string> m_Words;
        typename WordList<std::string>::Iterator m_Iterator;
    };
} // namespace PerformanceEvaluation
