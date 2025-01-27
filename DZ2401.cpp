#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

char** getMatrix(int size_x, int size_y) {
    char** mat = new char* [size_x];
    for (int i = 0; i < size_x; i++) {
        mat[i] = new char[size_y];
        for (int j = 0; j < size_y; j++) {
            mat[i][j] = ' ';
        }
    }
    return mat;
}

void printMat(char** mat, int size_x, int size_y) {
    system("cls");  
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

struct Fig {
    int id = 1;
    char field[4][4] = {
        {' ', ' ', ' ', ' '},
        {' ', '*', '*', ' '},
        {' ', '*', '*', ' '},
        {' ', ' ', ' ', ' '}
    };
};

void RotateMatrix(char fig[4][4], char newFig[4][4], int angle) {
    switch (angle) {
    case 0:
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                newFig[i][j] = fig[i][j];
        break;
    case 1:
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                newFig[j][3 - i] = fig[i][j];
        break;
    case 2:
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                newFig[3 - i][3 - j] = fig[i][j];
        break;
    case 3:
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                newFig[3 - j][i] = fig[i][j];
        break;
    }
}

int main() {
    Fig figure;
    int rotationAngle = 0;
    char newFigure[4][4];

    while (true) {
        printMat(getMatrix(10, 10), 10, 10);  
        RotateMatrix(figure.field, newFigure, rotationAngle);  
        printMat(newFigure, 4, 4); 

        if (_kbhit()) {
            char key = _getch();
            if (key == 'q') break; 
            if (key == 'r') {
                rotationAngle = (rotationAngle + 1) % 4;  
            }
        }
        Sleep(100); 
    }

    return 0;
}
