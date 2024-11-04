#include <iostream>

int main() {
    int N; 
    std::cout << "Введите количество дней: ";
    std::cin >> N;

    int totalDistance = 0; 
    int dailyDistance = 15; 

    for (int day = 1; day <= N; ++day) {
        totalDistance += dailyDistance; 
        dailyDistance += 2; 
    }

    std::cout << "Общее расстояние, пройденное улиткой за " << N << " дней: " << totalDistance << " см." << std::endl;

    return 0;
}
