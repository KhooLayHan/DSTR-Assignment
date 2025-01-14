// C Headers
#include <cstdio>

// C++ Headers
#include <cassert>
#include <iostream>
#include <string>

// Modules 
#include "FileHandling.cpp"
#include "LinkedList.cpp"

// ! Not allow to use this list of built-in containers: https://www.geeksforgeeks.org/containers-cpp-stl/
 
int main(int argc, char** argv)
{
    PerformanceEvaluation::LinkedList<std::string> linked_list;

    linked_list.addBegin("One");
    linked_list.addBegin("Two");
    linked_list.addEnd("Three");
    linked_list.addEnd("Four");
    linked_list.display();
    std::cout << "----------------" << std::endl;
    linked_list.deleteNode("One");
    linked_list.display();

    std::cout << "\nIgnore: HelloWorld\n";
    if (argc == 1)  {
        std::cout << "No command-line arguments specified.\n";
    } else {
        std::cout << argv[0] << "\t" << argv[1] << "\n";
    }

    std::cout << "----------------" << std::endl;
    PerformanceEvaluation::FileHandling::readFile("sample.txt");
}
