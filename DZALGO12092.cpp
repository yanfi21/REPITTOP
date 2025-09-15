#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    
    return -1;
}

int main() {
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18;
    
    int result = interpolationSearch(arr, n, x);
    
    if (result != -1) {
        cout << "Элемент " << x << " найден на позиции " << result << endl;
    } else {
        cout << "Элемент " << x << " не найден" << endl;
    }
    
    return 0;
}
