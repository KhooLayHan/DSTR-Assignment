// #pragma once

#include <chrono>
#include <iostream>
#include <string>

#include "Benchmark.h"
#include "SimpleLogger.h"
#include "SimpleFileLogger.cpp"
#include "SimpleConsoleLogger.cpp"
#include "SimpleLoggingService.cpp"

namespace PerformanceEvaluation {

    void Benchmark::startTimer() {
        start_time = Clock::now();
        is_running = true;
    }

    void Benchmark::endTimer() {
        if (is_running == false) {
            // SimpleLogger::Warn("System has not started benchmarking the program.", LogHandler::FILE);
            SimpleConsoleLogger console;
            SimpleLoggingService::UseDebugLogger(console, "System has not started benchmarking the program."); 

            return;
        }   

        end_time = Clock::now();
        is_running = false;

        duration();
    }            

    void Benchmark::duration(TimeUnit time_unit) {
        using std::chrono::duration_cast;
        
        checkBenchmarkIsRunning();

        // By default, it should be set to microseconds
        auto duration = duration_cast<Microseconds>(end_time - start_time).count();
        
        // Otherwise,check what unit is preferred and set it accordingly
        switch (time_unit) {
            case TimeUnit::SECONDS:
                duration = duration_cast<Seconds>(end_time - start_time).count(); 
                break;
            case TimeUnit::MICROSECONDS:
                break;
            case TimeUnit::MILLISECONDS:
                duration = duration_cast<Milliseconds>(end_time - start_time).count(); 
                break;
            case TimeUnit::NANOSECONDS:
                duration = duration_cast<Nanoseconds>(end_time - start_time).count(); 
                break;
        }

        std::cout << "Duration taken: " << duration << setTimeUnit(time_unit) << ".\n";
    }

    void Benchmark::durationSeconds() {
        checkBenchmarkIsRunning();  

        auto duration = std::chrono::duration_cast<Seconds>(end_time - start_time).count();
        std::cout << "Duration taken: " << duration << "s\n";
    }

    void Benchmark::durationMicroseconds() {
        checkBenchmarkIsRunning();

        auto duration = std::chrono::duration_cast<Microseconds>(end_time - start_time).count();
        std::cout << "Duration taken: " << duration << "μs\n";
    }

    void Benchmark::durationMilliseconds() {
        checkBenchmarkIsRunning();

        auto duration = std::chrono::duration_cast<Milliseconds>(end_time - start_time).count();
        std::cout << "Duration taken: " << duration << "ms\n";
    }

    void Benchmark::durationNanoseconds() {
        checkBenchmarkIsRunning();

        auto duration = std::chrono::duration_cast<Nanoseconds>(end_time - start_time).count();
        std::cout << "Duration taken: " << duration << "ns\n";
    }

    void Benchmark::checkBenchmarkIsRunning() {
        if (is_running) 
            return;

        SimpleConsoleLogger console;
        SimpleLoggingService::UseDebugLogger(console, "The benchmark is still running. Stop it to get the duration."); 
    }

    std::string_view Benchmark::setTimeUnit(TimeUnit time_unit) {
        std::string_view unit = "";
        
        switch (time_unit) {
            case TimeUnit::SECONDS:
                unit = "s";
                break;
            case TimeUnit::MICROSECONDS:
                unit = "μs";
                break;
            case TimeUnit::MILLISECONDS:
                unit = "ms";
                break;
            case TimeUnit::NANOSECONDS:
                unit = "ns";
                break;
        }

        return unit;
    } 
} // namespace PerformanceEvaluation