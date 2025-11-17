#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;

        if (left_child < n && arr[i] < arr[left_child]) return false;
        if (right_child < n && arr[i] < arr[right_child]) return false;
    }
    return true;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && arr[left_child] > arr[largest]) largest = left_child;
    if (right_child < n && arr[right_child] > arr[largest]) largest = right_child;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void ascHeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {8, 7, 6, 5, 4};
    int n = 5;

    if (isMaxHeap(arr, n))
        cout << "Array is a Max Heap"<< endl;
    else
        cout << "Array is NOT a Max Heap" << endl;

    ascHeapSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
