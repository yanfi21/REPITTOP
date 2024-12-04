#include <iostream>
#include <vector>
#include <stdexcept>

int findMin(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("The list is empty.");
    }

    int minElement = numbers[0];
    for (const int& number : numbers) {
        if (number < minElement) {
            minElement = number;
        }
    }
    return minElement;
}

int main() {
    std::vector<int> numbers = {3, 5, 7, 2, 8, -1, 4};
    
    try {
        int min = findMin(numbers);
        std::cout << "Minimum element: " << min << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
