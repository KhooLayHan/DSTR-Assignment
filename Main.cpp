// C Headers
#include <cstdio>

// Header files

#include "System.h"

int main(int argc, char** argv)
{
    PerformanceEvaluation::System::Init(argc, argv);
    PerformanceEvaluation::System::Run();
    PerformanceEvaluation::System::ShutDown();
}