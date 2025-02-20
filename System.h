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
            static void Init(int argc, char** argv) {
                assert(!s_Instance && "System is not initialize.");
                
                s_Instance = new System;

                ConfigManager config;

                config.LoadFromArgs(argc, argv);
            }

            static void Run() {
            }
            
            static void ShutDown() {
                delete s_Instance;
                s_Instance = nullptr;
            }
        protected:
            static System& GetInstance() {
                if (s_Instance == nullptr)
                    s_Instance = new System();

                return *s_Instance;
            }

            System(const System&) = delete;
            System& operator=(const System&) = delete;
        private:
            System() {
                std::cout << "System constructor.\n";  
            }

            ~System() {
                std::cout << "System destructor.\n";
                std::cout << s_AllocationCount << " allocations.\n";
            }

            inline static System* s_Instance = nullptr;
    };
}

#endif