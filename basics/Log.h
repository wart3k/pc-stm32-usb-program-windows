#ifndef PC_STM32_USB_PROGRAM_WINDOWS_LOG_H
#define PC_STM32_USB_PROGRAM_WINDOWS_LOG_H

#include <iostream>
#include <fstream>
#include <mutex>
#include <chrono>
#include <ctime>

class Logger {
public:
    static Logger& instance() {
        static Logger logger;
        return logger;
    }

    template<typename T>
    Logger& operator<<(const T& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        print(value);
        return *this;
    }

    Logger& operator<<(std::ostream& (*manip)(std::ostream&)) {
        std::lock_guard<std::mutex> lock(mutex_);
        manip(log_file_);
        manip(std::cout);
        return *this;
    }

private:
    Logger() {
        log_file_.open("asd.txt");
    }

    ~Logger() {
        log_file_.close();
    }

    void print(const char* value) {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        log_file_ << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] " << value;
        std::cout << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] " << value;
    }

    void print(const std::string& value) {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        log_file_ << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] " << value;
        std::cout << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] " << value;
    }

    void print(const std::vector<char>& value) {
        std::string str(value.begin(), value.end());
        str.erase(std::remove(str.begin(), str.end(), ','), str.end());
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        log_file_ << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] " << str;
        std::cout << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] " << str;
    }

    template<typename T>
    void print(const std::vector<T>& value) {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        log_file_ << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] [";
        std::cout << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] [";
        for (const auto& item : value) {
            print(item);
            if (&item != &value.back()) {
                log_file_ << ", ";
                std::cout << ", ";
            }
        }
        log_file_ << "]";
        std::cout << "]";
    }

    template<typename T, size_t N>
    void print(const T(&value)[N]) {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        log_file_ << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] [";
        std::cout << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] [";
        for (size_t i = 0; i < N; ++i) {
            print(value[i]);
            if (i != N - 1) {
                log_file_ << ", ";
                std::cout << ", ";
            }
        }
        log_file_ << "]";
        std::cout << "]";
    }

    std::ofstream log_file_;
    std::mutex mutex_;
};

#endif // PC_STM32_USB_PROGRAM_WINDOWS_LOG_H