// #pragma once

#include <array>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

#include "FileHandling.h"

#include "Array.cpp"
#include "Dataset.h"
#include "LinkedList.h"
#include "SimpleLogger.h"

namespace PerformanceEvaluation {

    void FileHandling::appendFileContent(const std::string& src_file_path, const std::string& dest_file_path) {
        std::ifstream input_file(src_file_path);
        std::ofstream output_file(dest_file_path, std::ios::app);

        checkReadFileValidity(src_file_path, input_file);
        checkWriteFileValidity(dest_file_path, output_file);

        std::string line;
        
        if (std::getline(input_file, line)) {
            while (std::getline(input_file, line)) 
                output_file << line << "\n";
        }

        std::string_view message = "Contents of file " + src_file_path 
            + " was successfully appended to file " + dest_file_path + ".";
            
        SimpleLogger::Info(message, LogHandler::FILE);

        input_file.close();
        output_file.close();
    }

    void FileHandling::readFile(const std::string& file_path, LinkedList& linked_list) {
        std::ifstream file(file_path);
        
        checkReadFileValidity(file_path, file);

        // std::vector<Dataset> datasets;
        Dataset dataset;
        std::string data;
        
        if (std::getline(file, data)) {
            while (std::getline(file, data)) {                                        
                Dataset dataset = parseCSV(data);
                // datasets.push_back(dataset);
                linked_list.insertEnd(dataset);
            }
        }

        file.close();
        
        // for (const auto& dataset : datasets) {
        //     dataset.display();
        //     std::cout << "------------\n";
        // }
    }

    void FileHandling::writeFile(const std::string& file_path, std::string_view message) {
        std::ofstream file(file_path);
        
        checkWriteFileValidity(file_path, file);

        file << message;                
        file.close();

        SimpleLogger::Info("Successfully write to file " + file_path, LogHandler::FILE);
    }

    void FileHandling::appendFile(const std::string& file_path, std::string_view message) {
        std::ofstream file(file_path, std::ios::app);
        
        checkAppendFileValidity(file_path, file);

        file << message;                
        file.close();

        // SimpleLogger::Info("Successfully appended to file " + file_path, LogHandler::FILE);
    }

    void FileHandling::readCSV(const std::string& file_path, LinkedList& linked_list) {
        std::ifstream file(file_path, std::ios::binary);
        
        checkReadFileValidity(file_path, file);

        Dataset dataset;
        std::string data;

        if (std::getline(file, data)) {
            while (std::getline(file, data)) {                                    
            
                // Dataset dataset = parseCSV(data);
                auto [id, title, text, subject, date] = parseCSV(data);
                // datasets.push_back(dataset);
                linked_list.insertEnd({ id, title, text, subject, date });
            }
        }
            
            // // std::cout << line << "\n";

            // std::getline(line, dataset.title, COMMA);
            // std::getline(line, dataset.text, COMMA);
            // std::getline(line, dataset.subject, COMMA);
            // std::getline(line, dataset.date, COMMA);
        
            // linked_list.insertBegin(dataset);
            // linked_list.addBegin(dataset.subject);
            // linked_list.addBegin(dataset.text);
            // linked_list.addBegin(title);

            // insertLinkedList(title, text, subject, date);

            // std::cout << "\nLine " << ++i << ": \n\t";
            // std::cout << dataset.title << "\n\t" 
            //     << dataset.text << "\n\t"
            //     << dataset.subject << "\n\t"
            //     << dataset.text << "\n"; 
        // }

        file.close();
    }

    // TODO: Update this to support Array implementation
    // void FileHandling::readCSV(const std::string& file_path, LinkedList& linked_list) {
    //     std::ifstream file(file_path, std::ios::binary);
        
    //     checkReadFileValidity(file_path, file);

    //     Dataset dataset;
    //     std::string data;

    //     if (std::getline(file, data)) {
    //         while (std::getline(file, data)) {                                    
            
    //             // Dataset dataset = parseCSV(data);
    //             auto [id, title, text, subject, date] = parseCSV(data);
    //             // datasets.push_back(dataset);
    //             linked_list.insertEnd({ id, title, text, subject, date });
    //         }
    //     }
    
    //     file.close();
    // }

    void FileHandling::checkReadFileValidity(const std::string& file_path, const std::ifstream& file) {
        if (!file) { 
            SimpleLogger::Warn("Reading file " + file_path + " is not found.", LogHandler::FILE);
            return; 
        }
    }

    void FileHandling::checkWriteFileValidity(const std::string& file_path, const std::ofstream& file) {
        if (!file) { 
            SimpleLogger::Warn("Writing file " + file_path + "is not found.", LogHandler::FILE);
            return; 
        }
    }

    void FileHandling::checkAppendFileValidity(const std::string& file_path, const std::ofstream& file) {
        if (!file) { 
            SimpleLogger::Warn("Appending file " + file_path + "is not found.", LogHandler::FILE);
            return; 
        }
    }

    Dataset FileHandling::parseCSV(const std::string& line) {
        constexpr size_t MAX_FIELDS_SIZE = 4;
        
        std::array<std::string, MAX_FIELDS_SIZE> field = { "" };
        // std::vector<std::string> field;
        std::string token;
        bool is_inside_quotes = false;
        size_t field_index = 0;

        std::string mock_line = line;

        // Trim whitespace, carriage returns ('\r'), and newlines ('\n') characters trailing '\r' characters
        mock_line.erase(0, mock_line.find_first_not_of(" \t\r\n")); // Trim leading
        mock_line.erase(mock_line.find_last_not_of(" \t\r\n") + 1); // Trim trailing
        
        // // Trim whitespace, carriage returns ('\r'), and newlines ('\n') characters trailing '\r' characters
        // while (!mock_line.empty() && (mock_line.back() == '\r' || mock_line.back() == '\n')) {
        //     mock_line.pop_back();
        // }

        // Edge case where line is entirely of `"\r\r\r\r\r\r` ...
        if (mock_line == "\"" || mock_line.empty() || mock_line == "\"\r\r\r\r\r\r\r") {
            // std::cerr << "⚠️ Warning: Skipping invalid line - " << line << "\t" << mock_line << "\n";
            return {}; // Return empty dataset
        }

        for (size_t i = 0; i < mock_line.size(); ++i) {
            char current = mock_line[i];

            if (current == '"') {
                // Handle embedded double quotes
                if (i + 1 < mock_line.size() && mock_line[i + 1] == '"') {
                    token += '"'; // Keep one quote
                    ++i; // Skip next quote  
                } else {
                    is_inside_quotes = !is_inside_quotes; // Toggle flag
                }
            } 

            // if (current == '"' && (i == 0 || mock_line[i - 1] != '\\')) {
                
            //     // Toggle insideQuotes flag when encountering unescaped quotes
            //     is_inside_quotes = !is_inside_quotes;
            
            else if (current == ',' && !is_inside_quotes) {
                
                // If we encounter a comma outside quotes, add token to the result
                if (field_index < MAX_FIELDS_SIZE)
                    field[field_index++] = token;
                
                token.clear();
            } else {
                // Append character to the token
                token += current;
            }
        }

        // Add the last token to the result
        if (field_index < MAX_FIELDS_SIZE) 
            field[field_index] = token;

        static int32_t id;
        Dataset dataset;
        
        // To ensure there are exactly four fields
        if (field_index != MAX_FIELDS_SIZE - 1) {
            std::string message = std::to_string(dataset.id) 
                + ": Unexpected number of fields in line:\n" + mock_line + "\n\n=>Original:\n\n" + line + "\n\n-----------";    

            // SimpleLogger::Fatal(message, LogHandler::CONSOLE);
            
            // dataset.title   = "error_field[0]";
            // dataset.text    = "error_field[1]";
            // dataset.subject = "error_field[2]";
            // dataset.date    = "error_field[3]";
            // dataset.id = 0;
        } else {
            id++;
            dataset.title   = field[0];
            dataset.text    = field[1];
            dataset.subject = field[2];
            dataset.date    = field[3];

            return { id, field[0], field[1], field[2], field[3] };
        }
        
        return {};
    }
}





            // void readFile() {
            //     std::ifstream file(file_path);
                
            //     checkFileValidity(file);

            //     std::string data;

            //     while (std::getline(file, data)) {
            //         std::cout << data << std::endl;
            //     }
            // }
