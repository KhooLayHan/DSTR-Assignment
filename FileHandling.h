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
            
            static void ReadCSV(const FilePath&, LinkedList&);

            static void WriteFile(const FilePath&, const std::string&);

            static void AppendFile(const FilePath&, const std::string&);
            
            static void AppendFileContent(const FilePath&, const FilePath&);

            static void CheckReadFileValidity(const FilePath&, const std::ifstream&);

            static void CheckWriteFileValidity(const FilePath&, const std::ofstream&);

            static void CheckAppendFileValidity(const FilePath&, const std::ofstream&);

            static Dataset& ParseCSV(const FilePath&);
            
            static Dataset& CleanCSV(const FilePath&);
        private:
            FilePath m_FilePath;
            // LinkedList linked_list;
    };
} // namespace PerformanceEvaluation


            // ~FileHandling() {
            //     file_path.close();
            // }   // static void readCSV(const std::string& file_path, LinkedList& linked_list) {
            //     std::ifstream file(file_path);
        
            //     checkReadFileValidity(file_path, file);

            //     Dataset dataset;
            //     std::string data;
                
            //     if (std::getline(file, data)) {
            //         while (std::getline(file, data)) {                                    
                    
            //             Dataset dataset = parseCSV(data);
            //             // datasets.push_back(dataset);
            //             linked_list.insertEnd(dataset);
            //         }
            //     }
                
            //     file.close();
            // }

                        // static void checkReadFileValidity(const std::string& file_path, const std::ifstream& file) {
            //     if (!file) { 
            //         SimpleLogger::Warn("Reading file " + file_path + " is not found.", LogHandler::FILE);
            //         return; 
            //     }
            // }

            // static Dataset parseCSV(const std::string& line) {
            //     constexpr size_t MAX_FIELDS_SIZE = 4;
        
            //     std::array<std::string, MAX_FIELDS_SIZE> field;
            //     // std::vector<std::string> field;
            //     std::string token;
            //     bool is_inside_quotes = false;
            //     size_t field_index = 0;

            //     for (size_t i = 0; i < line.size(); ++i) {
            //         char current = line[i];

            //         if (current == '"' && (i == 0 || line[i - 1] != '\\')) {
                        
            //             // Toggle insideQuotes flag when encountering unescaped quotes
            //             is_inside_quotes = !is_inside_quotes;
                    
            //         } else if (current == ',' && !is_inside_quotes) {
                        
            //             // If we encounter a comma outside quotes, add token to the result
            //             if (field_index < MAX_FIELDS_SIZE)
            //                 field[field_index++] = token;
                        
            //             token.clear();
            //         } else {
            //             // Append character to the token
            //             token += current;
            //         }
            //     }

            //     // Add the last token to the result
            //     if (field_index < MAX_FIELDS_SIZE) 
            //         field[field_index] = token;

            //     Dataset dataset;
            //     dataset.id++;
                
            //     // To ensure there are exactly four fields
            //     if (field_index != MAX_FIELDS_SIZE - 1) {
            //         SimpleLogger::Fatal("Unexpected number of fields in line" + line, LogHandler::FILE);
            //     } else {
            //         dataset.title   = field[0];
            //         dataset.text    = field[1];
            //         dataset.subject = field[2];
            //         dataset.date    = field[3];
            //     }
                
            //     return dataset;
            // }
