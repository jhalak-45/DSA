#include <iostream>
using namespace std;

void exchangeSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 34};
    int n = sizeof(arr)/sizeof(arr[0]);
    exchangeSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
