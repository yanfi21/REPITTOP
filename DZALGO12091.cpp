#include <iostream>
using namespace std;

void insertSort(int arr[], int n, int& compares, int& swaps) {
    compares = 0;
    swaps = 0;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        compares++;
        while (j >= 0 && arr[j] > key) {
            compares++;
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(int arr[], int n, int& compares, int& swaps) {
    compares = 0;
    swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            compares++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 10;
    int arr[n] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    
    cout << "Исходный массив: ";
    printArray(arr, n);
    cout << endl;
    
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }
    
    int insComp, insSwap;
    insertSort(arr1, n, insComp, insSwap);
    
    cout << "Сортировка вставками:" << endl;
    cout << "Сравнений: " << insComp << endl;
    cout << "Обменов: " << insSwap << endl << endl;
    
    int selComp, selSwap;
    selectionSort(arr2, n, selComp, selSwap);
    
    cout << "Сортировка выбором:" << endl;
    cout << "Сравнений: " << selComp << endl;
    cout << "Обменов: " << selSwap << endl << endl;
    
    cout << "Сортировка вставками эффективнее по сравнениям: " 
         << (insComp < selComp ? "Да" : "Нет") << endl;
    cout << "Сортировка вставками эффективнее по обменам: " 
         << (insSwap < selSwap ? "Да" : "Нет") << endl;
    
    return 0;
}


