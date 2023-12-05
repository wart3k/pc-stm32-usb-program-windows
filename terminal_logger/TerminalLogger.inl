#include "TerminalLogger.h"

#include <iomanip>
#include <chrono>
#include <ctime>
#include <iostream>
#include <format>

DebugLevelTable Log::logLevel_ = DebugLevelTable::INFO;

std::tm* get_current_time() {
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    return std::localtime(&now);
}

template<typename... Args>
void Log::System(const std::string& logMessage, Args&&... args) {
    Log::LogHelper(DebugLevelTable::SYSTEM, logMessage, std::forward<Args>(args)...);
}

template<typename... Args>
void Log::Critical(const std::string &logMessage, Args&&... args) {
    Log::LogHelper(DebugLevelTable::CRITICAL, logMessage, std::forward<Args>(args)...);
}

template<typename... Args>
void Log::Error(const std::string &logMessage, Args&&... args) {
    Log::LogHelper(DebugLevelTable::ERROR, logMessage, std::forward<Args>(args)...);
}

template<typename... Args>
void Log::Warning(const std::string &logMessage, Args&&... args) {
    Log::LogHelper(DebugLevelTable::WARNING, logMessage, std::forward<Args>(args)...);
}

template<typename... Args>
void Log::Info(const std::string &logMessage, Args&&... args) {
    Log::LogHelper(DebugLevelTable::INFO, logMessage, std::forward<Args>(args)...);
}

template<typename... Args>
void Log::Debug(const std::string &logMessage, Args&&... args) {
    Log::LogHelper(DebugLevelTable::DEBUG, logMessage, std::forward<Args>(args)...);
}

template<typename... Args>
void Log::Trace(const std::string &logMessage, Args&&... args) {
    Log::LogHelper(DebugLevelTable::TRACE, logMessage, std::forward<Args>(args)...);
}

template<typename... Args>
void Log::LogHelper(DebugLevelTable logLevel, const std::string& logMessage, Args&&... args) {
    if(logLevel <= logLevel_) {
        std::cout << std::format("[{:%Y-%m-%d %H:%M:%S}][{}]: ",
                                 std::chrono::system_clock::now(),
                                 Log::LevelToString(logLevel))
                  << std::format(logMessage, std::forward<Args>(args)...)
                  << std::endl;
    }
}

std::string Log::LogPreamble() {
    std::ostringstream oss;
    oss << "[" << std::put_time(get_current_time(), "%Y-%m-%d %H:%M:%S") << "] ";
    return oss.str();
}

std::string Log::LevelToString(DebugLevelTable debugLevel) {
    switch (debugLevel) {
        case DebugLevelTable::SYSTEM:
            return " SYSTEM";
        case DebugLevelTable::ERROR:
            return "  ERROR";
        case DebugLevelTable::WARNING:
            return "WARNING";
        case DebugLevelTable::INFO:
            return "   INFO";
        case DebugLevelTable::DEBUG:
            return "  DEBUG";
        case DebugLevelTable::TRACE:
            return "  TRACE";
        default:
            return "  UNDEF";
    }
}