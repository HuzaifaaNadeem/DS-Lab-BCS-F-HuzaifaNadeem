#include <iostream>
using namespace std;

void fix_heap_at_index(int arr[], int n, int i) {
    int largest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])  largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        fix_heap_at_index(arr, n, largest);
    }
}

void convert_min_to_max(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        fix_heap_at_index(arr, n, i);
}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = 10;

    convert_min_to_max(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
