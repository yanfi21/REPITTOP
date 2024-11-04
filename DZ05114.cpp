#include <iostream>
#include <vector>

bool isPrime(int number) {
    if (number < 2) return false; 
    for (int i = 2; i * i <= number; ++i) { 
            return false; 
        }
    }
    return true; 

int main() {
    std::cout << "Простые числа в диапазоне от 2 до 1000:" << std::endl;
    
    for (int num = 2; num <= 1000; ++num) {
        if (isPrime(num)) {
            std::cout << num << " "; 
        }
    }
    
    std::cout << std::endl; 
    return 0;
}
