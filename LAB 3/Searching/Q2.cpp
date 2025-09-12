//Searching Q2

#include <iostream>
using namespace std;

int main() {
    int EmpNumber;
    cout << "Enter number of employee IDs: ";
    cin >> EmpNumber;

    int arr[100];  
    cout << "Enter employee IDs: ";
    for (int i = 0; i < EmpNumber; i++) {
        cin >> arr[i];
    }

    
    for (int i = 0; i < EmpNumber - 1; i++) {
        for (int j = 0; j < EmpNumber - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int search = 33;  // last two digits of roll number 24K-0533

    
    int low = 0, high = EmpNumber - 1;
    int index = -1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (arr[mid] == search) {
            index = mid;
            break;
        }
        else if (arr[mid] < search) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (index != -1) {
        cout << "Employee ID with last two digits " << search << " found at position " << index << ".\n";
    }
    else {
        
        int PositionInsert = low;
        
        for (int i = EmpNumber; i > PositionInsert; i--) {
            arr[i] = arr[i - 1];
        }
        arr[PositionInsert] = search;
        EmpNumber++;

        cout << "Employee ID with last two digits " << search << " not found. Inserted at position " << PositionInsert + 1 << ".\n";
        cout << "New Array: ";
        for (int i = 0; i < EmpNumber; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
