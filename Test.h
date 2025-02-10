/*
    Sample Example for creating a header and implementation file
*/

#pragma once

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>

#include "Dataset.h"

namespace PerformanceEvaluation {
    class Test {
        public:
            Test() {} // Default Constructor

            Test(int32_t id, std::string name) : m_Id(id), m_Name(name) {} // Parameterized Constructor

            ~Test() {} // Destructor

            void AddTest();

            std::string RenameTest(const std::string&);

            void DeleteTest(int32_t) const;

            static void SomeHelperFunc(const Dataset&);
            
            std::string ReadTest(const Dataset&) const;
        private:
            int32_t m_Id;
            std::string m_Name;
    };
}
#endif 