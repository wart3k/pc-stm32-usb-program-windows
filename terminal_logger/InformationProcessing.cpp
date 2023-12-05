//
// Created by WART3K on 05.12.2023.
//

#include "InformationProcessing.h"

#include "TerminalLogger.h"

//void InformationProcessing::PrintProgramInformation() {
//    Log::System("Starting project: {} Version: {}", project_name, project_version);
//}

void InformationProcessing::PrintLogLevelTest() {
    Log::System("This is a system message");
    Log::Critical("This is a critical message");
    Log::Error("This is a error message");
    Log::Warning("This is a warning message");
    Log::Info("This is a info message");
    Log::Debug("This is a debug message");
    Log::Trace("This is a trace message");

}
