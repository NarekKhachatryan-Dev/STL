#include <iostream>
#include <stdexcept>

class CustomException : public std::exception {
    std::string message;
public:
    explicit CustomException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};