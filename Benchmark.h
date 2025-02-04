#pragma once

#ifndef BENCHMARK_H
#define BENCHMARK

#include <chrono>
#include <iostream>
#include <string>

#include "SimpleLogger.h"

namespace PerformanceEvaluation {
    enum class TimeUnit {
        SECONDS = 0,
        MICROSECONDS = 1,
        MILLISECONDS = 2,
        NANOSECONDS = 3,
    };
    
    class Benchmark {
        using Clock = std::chrono::high_resolution_clock;
        using TimePoint = std::chrono::time_point<Clock>;
        using Seconds = std::chrono::seconds;
        using Microseconds = std::chrono::microseconds;
        using Milliseconds = std::chrono::milliseconds;
        using Nanoseconds = std::chrono::nanoseconds;

        public:
            Benchmark() 
                : is_running(false) {
                // startTimer();
            }

            ~Benchmark() {
                // endTimer();
            }
           
            void startTimer();
            
            void endTimer();

            void duration(TimeUnit time_unit = TimeUnit::MICROSECONDS);
            
            // template <typename Func>
            // auto duration(Func func) {
            //     return [func]{ 
            //         startTimer();
            //     func();
            //     endTimer(); }
                
            // }

            template<typename Func>
            auto measureDuration(Func func) {
                startTimer();
                func();
                endTimer(); 
            }
            
            void durationSeconds();

            void durationMicroseconds();

            void durationMilliseconds();

            void durationNanoseconds();

            void checkBenchmarkIsRunning();

        protected:
            std::string_view setTimeUnit(TimeUnit);

        private:
            TimePoint start_time;
            TimePoint end_time;
            bool is_running;
    }; 
} // namespace PerformanceEvaluation

#endif