#pragma once

#include <filesystem>
#include <fstream>
#include <memory>
#include <string>
#include <string_view>

#include "Array.h"
#include "Dataset.h"
#include "LinkedList.h"

namespace PerformanceEvaluation {
    using FilePath = std::filesystem::path;
    class FileHandling {
        public:
            FileHandling() {}
        
            FileHandling(const FilePath& file_path)
                : m_FilePath(file_path) {}

            FileHandling(FilePath&& file_path)
                : m_FilePath(std::move(file_path)) {}

            static void ReadFile(const FilePath&, LinkedList&);
            static void WriteFile(const FilePath&, const std::string&);
            static void AppendFile(const FilePath&, const std::string&);
            
            static void AppendFileContent(const FilePath&, const FilePath&);

            static void CheckReadFileValidity(const FilePath&, const std::ifstream&);
            static void CheckWriteFileValidity(const FilePath&, const std::ofstream&);
            static void CheckAppendFileValidity(const FilePath&, const std::ofstream&);

            static Dataset ParseCSV(const FilePath&);
            static Dataset CleanCSV(const FilePath&);
        private:
            FilePath m_FilePath;
    };
} // namespace PerformanceEvaluation