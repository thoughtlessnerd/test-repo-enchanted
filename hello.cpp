// Copyright 2024 Abhay
#include <iostream>

void printMessage(const std::string& message) {
    std::cout << message << std::endl;
}

int addNumbers(int a, int b) {
    return a + b;
}

int main() {
    printMessage("Hello, Clang Format!");
    
    int result = addNumbers(5, 7);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
