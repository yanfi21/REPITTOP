#include <iostream>

double power(double base, int exponent) {
    return (exponent == 0) ? 1 : (exponent < 0) ? 1 / power(base, -exponent) : base * power(base, exponent - 1);
}

int main() {
    double base;
    int exponent;
    
    std::cout << "Введите основание: ";
    std::cin >> base;
    std::cout << "Введите степень: ";
    std::cin >> exponent;

    std::cout << base << " в степени " << exponent << " равно " << power(base, exponent) << std::endl;

    return 0;
}
