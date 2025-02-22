#pragma once

#include <array>
#include <filesystem>
#include <fstream>
#include <memory>
#include <string>

#include "Array.h"
#include "Dataset.h"
#include "LinkedList.h"
#include "WordList.h"
#include "Vector.h"
#include "DynamicArray.h"

namespace PerformanceEvaluation {
    using FilePath = std::filesystem::path;
    class FileHandling {
        protected:
            struct OldDataset {
                std::string title;
                std::string text;
                std::string subject;
                std::string date;

                OldDataset(const std::array<std::string, 4> fields) : title(fields[0]), text(fields[1]), subject(fields[2]), date(fields[3]) {}
            };
        public:
            FileHandling() {}
        
            FileHandling(const FilePath& file_path)
                : m_FilePath(file_path) {}

            FileHandling(FilePath&& file_path)
                : m_FilePath(std::move(file_path)) {}

            static void ReadWordFromFile(const FilePath&, WordList&);
            
                // static void ReadFile(const FilePath&, Array&);
            static void ReadFile(const FilePath&, LinkedList&);
            
            static void WriteFile(const FilePath&, const std::string&);
            
            static void AppendFile(const FilePath&, const std::string&);
            static void AppendFileNewline(const FilePath&, const std::string&);
            
            static void AppendFileContent(const FilePath&, const FilePath&);

            static void CheckReadFileValidity(const FilePath&, const std::ifstream&);
            static void CheckWriteFileValidity(const FilePath&, const std::ofstream&);
            static void CheckAppendFileValidity(const FilePath&, const std::ofstream&);
        protected:
            static Dataset ParseCSV(const std::string&);
            static Dataset CleanParseAndMoreClean(const std::string&);

            static const std::string CleanFile(const std::ifstream&);

            static const std::string CleanField(const std::string&, const std::string&);

            static OldDataset ParseCSVLine(const std::string&);
        private:
            FilePath m_FilePath;
    };
} // namespace PerformanceEvaluation