#include <iostream>

int main() {
    const int SIZE = 20;
    const int RANGE = 10;
    int arr[SIZE];
    int frequency[RANGE] = {0};

    std::cout << "Введите " << SIZE << " целых чисел (от 0 до 9):\n";
    for (int i = 0; i < SIZE; i++) {
        std::cin >> arr[i];
        if (arr[i] >= 0 && arr[i] < RANGE) {
            frequency[arr[i]]++;
        } else {
            std::cout << "Ошибка: число должно быть от 0 до 9. Попробуйте снова.\n";
            i--;
        }
    }

    std::cout << "\nГистограмма:\n";
    for (int i = 0; i < RANGE; i++) {
        std::cout << i << ": ";
        for (int j = 0; j < frequency[i]; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}
