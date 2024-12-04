#include <iostream>
#include <vector>
#include <stdexcept>

int sumElements(const std::vector<int>& numbers) {
    int sum = 0;
    for (const int& number : numbers) {
        sum += number;
    }
    return sum;
}

int main() {
    std::vector<int> numbers = {3, 5, 7, 2, 8, -1, 4};

    int totalSum = sumElements(numbers);
    std::cout << "Сумма всех элементов: " << totalSum << std::endl;

    return 0;
}
