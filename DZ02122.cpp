#include <iostream>
#include <string>
#include <cctype> 

std::string toLowerCase(const std::string& input) {
    std::string result = input; 
    for (char& ch : result) { 
        ch = std::tolower(ch); 
    }
    return result; 
}

int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input); 
    std::string output = toLowerCase(input);
    std::cout << "Результат: " << output << std::endl;
    return 0;
}
