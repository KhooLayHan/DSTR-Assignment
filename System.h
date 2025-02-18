#pragma once

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

// C Headers
#include <cstdio>

// C++ Headers
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>

// Header files
#include "ConfigManager.h"
#include "Assignment.cpp"

static int s_AllocationCount = 0; 

void* operator new(size_t size) {
    // std::cout << "Allocated " << size << " bytes\n";
    s_AllocationCount++;
    return malloc(size);
}


namespace PerformanceEvaluation {
    class System {      
        public:
            System() {
                s_System = new System;
            }

            ~System() {
                if (s_System == nullptr) {
                    s_System = new System;
                }

                std::cout << s_AllocationCount << " allocations.\n";
                
                delete s_System;
            }

            void Init(int argc, int** argv) {
                ConfigManager
            }

            void Run() {
                
            }

            void ShutDown() {

            }
        private:
            inline static System* s_System;
    };
}

#endif