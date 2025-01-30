#include <iostream>
using namespace std;

int** getRandomMatrix(int size_X, int size_Y) {
    int** matrix = new int* [size_X];

    for (int i = 0; i < size_X; i++) {
        matrix[i] = new int[size_Y];

        for (int j = 0; j < size_Y; j++) {
            matrix[i][j] = rand();
        }
    }

    return matrix;
}
void printMatrix(int** matrix, int size_X, int size_Y) {
    for (int i = 0; i < size_X; i++) {


        for (int j = 0; j < size_Y; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int SumMatrix(int** mat, int size_x, int size_y) {
    int sum = 0;
    for (int i = 0;i < size_x;i++) {
        for (int j = 0;j < size_y;j++) {
            sum += mat[i][j];
        }
    }
    return sum;
}
int main()
{
    int** mat = getRandomMatrix(5, 5);
        
}
