#include <array>
#include <iostream>
#include <regex> 
#include <string>
#include <string_view>
#include <sstream>

#include <vector>

#include "FileHandling.h"

#include "SimpleFileLogger.h"
#include "SimpleConsoleLogger.h"
#include "SimpleLoggingService.h"

#include "DynamicArray.h"
#include "Vector.h"
namespace PerformanceEvaluation {
    // TODO: Update ReadFile() to support Array implementation instead, not LinkedList
    // void FileHandling::ReadFile(const FilePath& file_path, Array& array) {
    //     std::ifstream file(file_path);
        
    //     CheckReadFileValidity(file_path, file);

    //     if (std::string data;std::getline(file, data)) {
    //         while (std::getline(file, data)) {                                    
    //             const auto& [id, title, text, subject, date] = ParseCSV(data);
    //             // * array code here...
    //         }
    //     }
    
    //     file.close();
    // }

    void FileHandling::ReadFile(const FilePath& file_path, LinkedList& linked_list) {
        // std::ifstream file(file_path, std::ios::binary);
        std::ifstream file(file_path);
        
        CheckReadFileValidity(file_path, file);

        // const std::string& cleaned_file = CleanFile(file);  
        // std::istringstream stream(cleaned_file);
        std::string line;

        while (std::getline(file, line)) {
            if (line == "title,text,subject,date" || line == "title,text,subject,date\r") 
                continue;

            const auto& [id, title, text, subject, date] = CleanParseAndMoreClean(line);

            linked_list.InsertEnd(Dataset{ id, title, text, subject, date });

            // linked_list.InsertEnd({ id, title, text, subject, date });
        }

        // 1051, Title: "Ex-GOP Congressman Shreds Fellow Republicans For Not ‘Howling’ For Trump’s Impeachment (VIDEO)\r\r\r\r\r\r\r"
        
        file.close();
    }

    void FileHandling::ReadFile(const FilePath& file_path, Array<Dataset>& array) {
        std::ifstream file(file_path);
        
        CheckReadFileValidity(file_path, file);

        std::string line;
        
        while (std::getline(file, line)) {
            if (line == "title,text,subject,date" || line == "title,text,subject,date\r") 
                continue;

            // Parse the line into dataset fields
            const auto& [id, title, text, subject, date] = CleanParseAndMoreClean(line);
            
            // Insert parsed data into the array
            array.InsertEnd({ id, title, text, subject, date });
        }

        file.close();
    }

    void FileHandling::ReadWordFromFile(const FilePath& file_path, WordList& linked_list) {
        std::ifstream file(file_path);
        
        CheckReadFileValidity(file_path, file);

        const std::string& cleaned_file = CleanFile(file);  
        std::istringstream stream(cleaned_file);

        std::string text;
        std::string line;
        
        while (std::getline(stream, line)) {
            if (line == "title,text,subject,date" || line == "title,text,subject,date\r") 
                continue;
            
            const auto& [id, title, text, subject, date] = CleanParseAndMoreClean(line);
            
            auto text_parser = [](const std::string& text) {
                std::string word;
                std::regex word_pattern(R"(\b([A-Za-z0-9]+(?:-[A-Za-z0-9]+)*|(?:[A-Za-z]\.){2,})\b)");
                
                std::sregex_iterator it(text.begin(), text.end(), word_pattern);
                std::sregex_iterator end;

                while (it != end) {
                    word += it->str();
                    ++it;
                }

                return word;
            };

            const std::string& parsed_title = text_parser(title);
            const std::string& parsed_text = text_parser(text);
            const std::string& parsed_subject = text_parser(subject);
            const std::string& parsed_date = text_parser(date);

            FileHandling::AppendFileNewline("./Text/assignment.txt", parsed_title);
            FileHandling::AppendFileNewline("./Text/assignment.txt", parsed_text);
            FileHandling::AppendFileNewline("./Text/assignment.txt", parsed_subject);
            FileHandling::AppendFileNewline("./Text/assignment.txt", parsed_date);
            
            linked_list.InsertEnd(parsed_title);
            linked_list.InsertEnd(parsed_text);
            linked_list.InsertEnd(parsed_subject);
            linked_list.InsertEnd(parsed_date);

            // while (temp) {
            //     // temp->m_Data.type

            //     // temp = temp->m_Next;
            // }

            // linked_list.insertEnd({ id, title, text, subject, date });
        }
        
        // 1051, Title: "Ex-GOP Congressman Shreds Fellow Republicans For Not ‘Howling’ For Trump’s Impeachment (VIDEO)\r\r\r\r\r\r\r"
        
        file.close();
    }

    void FileHandling::WriteFile(const FilePath& file_path, const std::string& message) {
        std::ofstream file(file_path);
        
        CheckWriteFileValidity(file_path, file);

        file << message;                
        file.close();

        const std::string& ref_file_path = file_path; 

        // SimpleFileLogger file_logger;
        // SimpleLoggingService::UseInfoLogger(file_logger, "Successfully written to file " + ref_file_path + " with message: " + message + ".");
    }

    void FileHandling::AppendFile(const FilePath& file_path, const std::string& message) {
        std::ofstream file(file_path, std::ios::app);
        
        CheckAppendFileValidity(file_path, file);

        file << message;                
        file.close();
        
        const std::string& ref_file_path = file_path; 

        // SimpleFileLogger file_logger;
        // SimpleLoggingService::UseInfoLogger(file_logger, "Successfully appended to file " + ref_file_path + " with message: " + message + ".");
    }
    
    void FileHandling::AppendFileNewline(const FilePath& file_path, const std::string& message) {
        std::ofstream file(file_path, std::ios::app);
        
        CheckAppendFileValidity(file_path, file);

        file << message << "\n";                
        file.close();
        
        const std::string& ref_file_path = file_path; 

        // SimpleFileLogger file_logger;
        // SimpleLoggingService::UseInfoLogger(file_logger, "Successfully appended to file " + ref_file_path + " with message: " + message + ".");
    }

    void FileHandling::AppendFileContent(const FilePath& src_file_path, const FilePath& dest_file_path) {
        std::ifstream input_file(src_file_path);
        std::ofstream output_file(dest_file_path, std::ios::app);

        CheckReadFileValidity(src_file_path, input_file);
        CheckWriteFileValidity(dest_file_path, output_file);

        if (std::string line; std::getline(input_file, line)) {
            while (std::getline(input_file, line)) 
                output_file << line << "\n";
        }
        
        const std::string& source = src_file_path;
        const std::string& destination = dest_file_path;

        SimpleFileLogger file_logger;
        SimpleLoggingService::UseInfoLogger(file_logger, "Contents of file " + source + " was successfully appended to file " + destination + ".");
        
        input_file.close();
        output_file.close();
    }

    void FileHandling::CheckReadFileValidity(const FilePath& file_path, const std::ifstream& file) {
        const std::string& ref_file_path = file_path;
        
        if (!file) { 
            SimpleConsoleLogger console_logger;
            SimpleLoggingService::UseWarnLogger(console_logger, "Reading file " + ref_file_path + " is not found.");
            
            return; 
        }
    }

    void FileHandling::CheckWriteFileValidity(const FilePath& file_path, const std::ofstream& file) {
        const std::string& ref_file_path = file_path;
        
        if (!file) { 
            SimpleConsoleLogger console_logger;
            SimpleLoggingService::UseWarnLogger(console_logger, "Writing file " + ref_file_path + " is not found.");

            return; 
        }
    }

    void FileHandling::CheckAppendFileValidity(const FilePath& file_path, const std::ofstream& file) {
        const std::string& ref_file_path = file_path;
        
        if (!file) { 
            SimpleConsoleLogger console_logger;
            SimpleLoggingService::UseWarnLogger(console_logger, "Appending file " + ref_file_path + " is not found.");

            return; 
        }
    }

    const std::string FileHandling::CleanFile(const std::ifstream& file) {        
        // Read the entire file into a string
        std::ostringstream buffer;
        buffer << file.rdbuf();
        std::string file_content = buffer.str();

        // Remove all '\r' characters
        // file_content.erase(std::remove(file_content.begin(), file_content.end(), '\r'), file_content.end());

        return file_content;
    }

    Dataset FileHandling::ParseCSV(const std::string& line) {
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
            std::string message = std::to_string(dataset.m_Id) 
                + ": Unexpected number of fields in line:\n" + mock_line + "\n\n=>Original:\n\n" + line + "\n\n-----------";    

            // SimpleLogger::Fatal(message, LogHandler::CONSOLE);
            
            // dataset.title   = "error_field[0]";
            // dataset.text    = "error_field[1]";
            // dataset.subject = "error_field[2]";
            // dataset.date    = "error_field[3]";
            // dataset.id = 0;
        } else {
            id++;
            dataset.m_Title   = field[0];
            dataset.m_Text    = field[1];
            dataset.m_Subject = field[2];
            dataset.m_Date    = field[3];

            return { id, field[0], field[1], field[2], field[3] };
        }
        
        return {};
    }

    Dataset FileHandling::CleanParseAndMoreClean(const std::string& line) {        
        const auto& [title, text, subject, date] = ParseCSVLine(line);
        
        // auto clean_field = [&](const std::string& field, const std::string& placeholder) {
        //     return field.empty() ? placeholder : field;
        // };

        Dataset dataset;
        
        dataset.m_Id++;
        dataset.m_Title = CleanField(title, "No Title");
        dataset.m_Text = CleanField(text, "No Text");
        dataset.m_Subject = CleanField(subject, "No Subject");
        dataset.m_Date = CleanField(date, "No Date");

        return dataset;
    }

    const std::string FileHandling::CleanField(const std::string& field, const std::string& placeholder) {
        if (field.empty()) 
            return placeholder;
            
        std::string cleaned;
        for (char character : field) {
            // Keep only non-control characters (e.g., skip \r, \n)
            if (!std::iscntrl(character) || character == '\n') { // Preserve newlines if needed
                cleaned += character;
            }
        }

        // Trim whitespace, carriage returns ('\r'), and newlines ('\n') characters trailing '\r' characters
        cleaned.erase(0, cleaned.find_first_not_of(" \t\r\n")); // Trim leading
        cleaned.erase(cleaned.find_last_not_of(" \t\r\n") + 1); // Trim trailing
        
        return cleaned;
    }

    // ! 1052; Text fields crashes due to \r\r\r\r\r from title (I think)

    FileHandling::OldDataset FileHandling::ParseCSVLine(const std::string& line) {
        static constexpr size_t MAX_FIELD_SIZE = 4;
        
        std::array<std::string, 4> fields;

        // std::array<std::string, MAX_FIELD_SIZE> fields;
        size_t field_index = 0;
        std::string token;
        bool in_quotes = false;
        bool escape_next = false;
        
        // std::string line_ = CleanField(line, "");

        for (size_t i = 0; i < line.size(); ++i) {
            char character = line[i];
    
            if (escape_next) {
                token += character;
                escape_next = false;
            } else if (character == '\\') {
                escape_next = true;
            } else if (character == '"') {
                in_quotes = !in_quotes;
            } else if (character == ',' && !in_quotes) {
                if (field_index < MAX_FIELD_SIZE)
                    fields[field_index++] = token;
                token.clear();
            } else {
                token += character;
            }
        }
    
        // If there are more than 4 fields, then error!
        if (field_index > MAX_FIELD_SIZE - 1) {
            std::cout << token << "\n";
            SimpleConsoleLogger console;
            SimpleLoggingService::UseFatalLogger(console, "Unexpected number of fields in line; field_index == " + field_index + '.');
        }
        
        // Add the last field
        if (field_index < MAX_FIELD_SIZE)
            fields[field_index] = token;
        
        return { fields };
    }
}