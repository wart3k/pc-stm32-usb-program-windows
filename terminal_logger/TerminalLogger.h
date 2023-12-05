#ifndef PC_STM32_USB_PROGRAM_WINDOWS_TERMINAL_LOGGER_H
#define PC_STM32_USB_PROGRAM_WINDOWS_TERMINAL_LOGGER_H

#include <string>

enum class DebugLevelTable {
    SYSTEM      = 0,
    CRITICAL    = 1,
    ERROR       = 2,
    WARNING     = 3,
    INFO        = 4,
    DEBUG       = 5,
    TRACE       = 6
};

class Log {
public:
    template<typename... Args>
    static void System(const std::string& logMessage, Args&&... args);

    template<typename... Args>
    static void Critical(const std::string& logMessage, Args&&... args);

    template<typename... Args>
    static void Error(const std::string& logMessage, Args&&... args);

    template<typename... Args>
    static void Warning(const std::string& logMessage, Args&&... args);

    template<typename... Args>
    static void Info(const std::string& logMessage, Args&&... args);

    template<typename... Args>
    static void Debug(const std::string& logMessage, Args&&... args);

    template<typename... Args>
    static void Trace(const std::string& logMessage, Args&&... args);

private:

    template<typename... Args>
    static void LogHelper(DebugLevelTable logLevel, const std::string& logMessage, Args&&... args);

    static DebugLevelTable logLevel_;

    static std::string LogPreamble();

    static std::string LevelToString(DebugLevelTable debugLevel);
};

#include "TerminalLogger.inl"


#endif //PC_STM32_USB_PROGRAM_WINDOWS_TERMINAL_LOGGER_H
