// #include <iostream>
// #include <string>

// #include <chrono>
// #include <numeric>

// namespace PerformanceEvaluation {
//     class Benchmark {

//         public:
//             Benchmark() 
//                 : is_running(false) {
//                 // using namespace std::chrono_literals;
                

//                 // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
                
//                 // std::cout << duration.count() << "microseconds.\n"; 
//             }

//             void startTimer() {
//                 start_time = std::chrono::high_resolution_clock::now();
//                 is_running = true;
//             }

//             void endTimer() {
//                 // using namespace std::chrono_literals;
                
//                 // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
                
//                 // std::cout << duration.count() << "microseconds.\n";

//                 if (is_running == false) {
//                     std::cout << "Timer is not running.\n\n\n";
//                     return;
//                 }   

//                 end_time = std::chrono::high_resolution_clock::now();
//                 is_running = false;
//             }

//             void durationMicroseconds() {
//                 if (is_running == true) {
//                     std::cout << "\n\n\nTimer is still running. Stop it to get the duration.\n";
//                     return;
//                 }

//                 auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
//                 std::cout << "Duration taken: " << duration << "ms\n";
//             }

//             ~Benchmark() {
            
//             }

//         private:
//             std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
//             std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
//             bool is_running;
//     };
// }