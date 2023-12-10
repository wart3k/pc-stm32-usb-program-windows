#include "InformationProcessing.h"

#include "Log.h"

#include <array>
#include <vector>
#include <string>

void InformationProcessing::PrintLogLevelTest() {
    Logger::instance() << "Hello, world!\n";
    Logger::instance() << "This is a test.\n";
//    Logger::instance() << std::vector<int>{1, 2, 3} << "\n";
//    int arr[] = {4, 5, 6};
//    Logger::instance() << arr << "\n";
}
