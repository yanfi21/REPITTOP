#include <iostream>
#include <string>

std::string replaceVowelsWithUnderscore(const std::string& input) {
    std::string result = input; 
    for (char& ch : result) { 
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            ch = '_';
        }
    }
    return result; 
}

int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input); 
    std::string output = replaceVowelsWithUnderscore(input);
    std::cout << "Результат: " << output << std::endl;
    return 0;
}
