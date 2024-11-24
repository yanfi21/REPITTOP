#include <iostream>
#include <vector>

void printPascalsTriangle(int n) {
    std::vector<std::vector<int>> triangle(n);
    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) std::cout << " ";
        for (int j = 0; j <= i; ++j) std::cout << triangle[i][j] << " ";
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Введите количество строк треугольника Паскаля: ";
    std::cin >> n;
    printPascalsTriangle(n);
    return 0;
}
