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

#if __cplusplus < 202002L
    #error "Minimum C++20 is necessary to run the program. Please update accordingly."
#endif

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

                s_Instance->config.LoadFromArgs(argc, argv);
              
                s_Instance->config.EnsureFileSizeLimit("./CSV/combined.csv");
                
                s_Instance->config.EnsureFileSizeLimit("./Solutions/question_1.txt");
                s_Instance->config.EnsureFileSizeLimit("./Solutions/question_2.txt");
                s_Instance->config.EnsureFileSizeLimit("./Solutions/question_3.txt");
                
                // s_Instance->config.CreateFileOnStartup("./CSV/question_4.txt");
                // s_Instance->config.CreateFileOnStartup("./CSV/question_5.txt");
                // s_Instance->config.CreateFileOnStartup("./CSV/question_6.txt");
                // s_Instance->config.CreateFileOnStartup("./CSV/question_7.txt");
                // s_Instance->config.CreateFileOnStartup("./CSV/question_8.txt");
                // s_Instance->config.CreateFileOnStartup("./CSV/question_9.txt");
                // s_Instance->config.CreateFileOnStartup("./CSV/question_10.txt");

                std::cout << "---Performance Evaluation---\n";
                std::cout << "---      By Group 36     ---\n";
            }

            static void Run() {
            }
            
            static void ShutDown() {
                if (s_Instance) {
                    s_Instance->config.DestroyFileOnShutdown("./CSV/combined.csv");
                    
                    s_Instance->config.DestroyFileOnShutdown("./Solutions/question_1.txt");
                    s_Instance->config.DestroyFileOnShutdown("./Solutions/question_2.txt");
                    s_Instance->config.DestroyFileOnShutdown("./Solutions/question_3.txt");

                    // s_Instance->config.DestroyFileOnShutdown("./Solutions/question_4.txt");
                    // s_Instance->config.DestroyFileOnShutdown("./Solutions/question_5.txt");
                    // s_Instance->config.DestroyFileOnShutdown("./Solutions/question_6.txt");
                    // s_Instance->config.DestroyFileOnShutdown("./Solutions/question_7.txt");
                    // s_Instance->config.DestroyFileOnShutdown("./Solutions/question_8.txt");
                    // s_Instance->config.DestroyFileOnShutdown("./Solutions/question_9.txt");
                    // s_Instance->config.DestroyFileOnShutdown("./Solutions/question_10.txt");

                    delete s_Instance;
                    s_Instance = nullptr;
                }
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
            ConfigManager config;
    };
}

#endif