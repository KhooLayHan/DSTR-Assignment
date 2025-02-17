#pragma once

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <fstream>
#include <memory>
#include <string>
#include <string_view>

// #include "Array.h"
#include "Dataset.h"
#include "LinkedList.h"
#include "SimpleLogger.h"

namespace PerformanceEvaluation {
    class FileHandling {
        public:
            FileHandling() {}
        
            // FileHandling(const std::string& file_path)
            //     : file_path(file_path) {}

            // FileHandling(std::string&& file_path)
            //     : file_path(std::move(file_path)) {}

            static void readFile(const std::string&, LinkedList&);
            
            static void readCSV(const std::string&, LinkedList&);
            // static void readCSV(const std::string& file_path, LinkedList& linked_list) {
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

            static void writeFile(const std::string&, std::string_view);

            static void appendFile(const std::string&, std::string_view);
            
            static void appendFileContent(const std::string&, const std::string&);

            static void checkReadFileValidity(const std::string&, const std::ifstream&);
            // static void checkReadFileValidity(const std::string& file_path, const std::ifstream& file) {
            //     if (!file) { 
            //         SimpleLogger::Warn("Reading file " + file_path + " is not found.", LogHandler::FILE);
            //         return; 
            //     }
            // }

            static void checkWriteFileValidity(const std::string&, const std::ofstream&);

            static void checkAppendFileValidity(const std::string&, const std::ofstream&);

            static Dataset parseCSV(const std::string&);
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

        private:
            std::string file_path;
            // LinkedList linked_list;
    };
} // namespace PerformanceEvaluation

#endif

            // ~FileHandling() {
            //     file_path.close();
            // }