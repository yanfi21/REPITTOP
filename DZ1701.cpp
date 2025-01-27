#include <iostream>
using namespace std;

int** getMatrix(int size_X, int size_Y) {
    int** matrix = new int* [size_X];

    for (int i = 0; i < size_X; i++) {
        matrix[i] = new int[size_Y];

        for (int j = 0; j < size_Y; j++) {
            matrix[i][j] = i + j;
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

void RotateMatrix(int** mat, int size_x, int size_y, int angle) {
    int** rotateMat = getMatrix(5, 5);
    switch (angle) {
    case 90:
        for (int i = 0; i < size_x;i++) {
            for (int j = 0;j < size_y;j++) {
                rotateMat[j][size_y - 1 - i] = mat[i][j];
            }
        }
        break;
    case 180:
        for (int i = 0; i < size_x;i++) {
            for (int j = 0;j < size_y;j++) {
                rotateMat[size_x - 1 - i][size_y - 1 - j] = mat[i][j];
            }
        }
        break;
    case 270:
        for (int i = 0; i < size_x;i++) {
            for (int j = 0;j < size_y;j++) {
                rotateMat[size_x - 1 - j][i] = mat[i][j];
            }
        }
        break;
    }
    for (int i = 0;i < size_x;i++) {
        for (int j = 0;j < size_y;j++) {
            mat[i][j] = rotateMat[i][j];
        }
    }
    
}
int main()
{
    int** mat = getMatrix(5, 5);
    //printMatrix(mat, 5, 5);
    RotateMatrix(mat, 5, 5, 90);
    printMatrix(mat, 5, 5);
}
