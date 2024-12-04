#include <iostream>
#include <vector>
#include <stdexcept>

int findMax(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("The list is empty.");
    }

    int maxElement = numbers[0];
    for (const int& number : numbers) {
        if (number > maxElement) {
            maxElement = number;
        }
    }
    return maxElement;
}

int main() {
    std::vector<int> numbers = {3, 5, 7, 2, 8, -1, 4};
    
    try {
        int max = findMax(numbers);
        std::cout << "Maximum element: " << max << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


