#include <iostream>

void transposeMatrix(int** matrix, int rows, int cols) {
    int** transposed = new int*[cols];
    for (int i = 0; i < cols; ++i) {
        transposed[i] = new int[rows];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    std::cout << "Транспонированная матрица:" << std::endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            std::cout << transposed[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < cols; ++i) {
        delete[] transposed[i];
    }
    delete[] transposed;
}

int main() {
    int rows, cols;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    transposeMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
