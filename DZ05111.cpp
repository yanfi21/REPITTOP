#include <iostream>

int main() {
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;

    int sum = 0;
    int temp = number;

    if (temp < 0) {
        temp = -temp;
    }

    while (temp > 0) {
        sum += temp % 10; 
        temp /= 10;       
    }

    std::cout << "Сумма цифр числа " << number << " равна " << sum << "." << std::endl;

    return 0;
}

