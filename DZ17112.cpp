#include <iostream>

void shakerSort(int* arr, int size) {
    int left = 0, right = size - 1;
    bool swapped;

    do {
        swapped = false;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right--;
        
        if (!swapped) break;

        swapped = false;
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        left++;
    } while (swapped);
}

int main() {
    int mas[] = {2, 1, 4, 5, 6, 4, 8, 4, 7, 9};
    int size = sizeof(mas) / sizeof(mas[0]);

    std::cout << "Исходный массив:\n";
    for (int n : mas) std::cout << n << " ";
    
    shakerSort(mas, size);

    std::cout << "\nОтсортированный массив:\n";
    for (int n : mas) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}
