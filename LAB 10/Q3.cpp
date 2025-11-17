#include <iostream>
using namespace std;

void heapify_down(int arr[], int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && arr[left_child] > arr[largest]) largest = left_child;
    if (right_child < n && arr[right_child] > arr[largest]) largest = right_child;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify_down(arr, n, largest);
    }
}

int kth_largest(int arr[], int n, int k) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_down(arr, n, i);

    for (int i = n - 1; i >= n - k; i--) {
        swap(arr[0], arr[i]);
        heapify_down(arr, i, 0);
    }

    return arr[n - k];
}

int main() {
    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int n1 = 7;

    int k1;
    cout << "Enter K: ";
    cin >> k1;

    cout << "Kth Largest: " << kth_largest(arr1, n1, k1) << endl;

    return 0;
}
