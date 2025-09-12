//Searching Q1

#include <iostream>
using namespace std;

int main() {
    int SizeArray, Search;
    cout << "Enter Size of array: ";
    cin >> SizeArray;
    int *arr;

    arr = new int[SizeArray];
    cout << "Enter " << SizeArray << " elements: " << endl;
    for (int i = 0; i < SizeArray; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter element to search for: ";
    cin >> Search;
    
    bool found = false;
    for (int i = 0; i < SizeArray; i++) {
        if (arr[i] == Search) {
            cout << "Element found at index: " << i << endl;
            found = true;
            break; 
        }
    }
    
    if (!found) {
        cout << "Element not found in the array." << endl;
    }
    
    
    delete[] arr;
    
    return 0;
}
