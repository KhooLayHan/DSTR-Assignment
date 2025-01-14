#include <iostream>
#include <fstream>
#include <memory>
#include <string>

namespace PerformanceEvaluation
{
    class FileHandling {
        public:
            FileHandling() = delete;
        
            FileHandling(const std::string& file_path)
                : file_path(file_path) {
                
            }

            FileHandling(std::string&& file_path)
                : file_path(std::move(file_path)) {
                
            }

            void checkFileValidity(std::ifstream file_path) {
                if (!file_path) { // or filepath.fail()
                    std::cerr << "Error opening file " << __FILE__ << " for reading.\n";
                    return; 
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

            // static void checkFileValidity(std::ifstream file_path) {
            //     if (!file_path) { // or filepath.fail()
            //         std::cerr << "Error opening file " << __FILE__ << " for reading.\n";
            //         return; 
            //     }
            // }

            static void readFile(const std::string& file_path) {
                std::ifstream file(file_path);
                
                if (!file) { // or filepath.fail()
                    std::cerr << "Error opening file " << __FILE__ << " for reading.\n";
                    return; 
                }

                std::string data;
                while (std::getline(file, data)) {
                    std::cout << data << std::endl;
                }

                file.close();
            }

            // ~FileHandling() {
            //     file_path.close();
            // }

        private:
            std::string file_path;
    };
} // namespace PerformanceEvaluation
