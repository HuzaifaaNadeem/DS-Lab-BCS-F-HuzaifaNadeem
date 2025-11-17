#include <iostream>
using namespace std;

class MaxHeap {
    int* arr;
    int capacity;
    int size;

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    int parent(int i) { 
		return (i - 1) / 2; 
	}
    int left(int i) { 
		return 2 * i + 1; 
	}
    int right(int i) { 
		return 2 * i + 2;
	}

    void insertKey(int k) {
        int i = size;
        arr[i] = k;
        size++;

        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);

        int largest = i;
        if (l < size && arr[l] > arr[largest]) largest = l;
        if (r < size && arr[r] > arr[largest]) largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void update_key(int i, int new_val) {
        int old_val = arr[i];
        arr[i] = new_val;

        if (new_val > old_val) {
            while (i != 0 && arr[parent(i)] < arr[i]) {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        } else {
            heapify(i);
        }
    }

    void delete_key(int i) {
        arr[i] = arr[size - 1];
        size--;
        update_key(i, arr[i]);
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h(10);

    h.insertKey(8);
    h.insertKey(7);
    h.insertKey(6);
    h.insertKey(5);
    h.insertKey(4);

    h.printHeap();

    h.update_key(3, 10);
    h.printHeap();

    h.delete_key(1);
    h.printHeap();

    return 0;
}
