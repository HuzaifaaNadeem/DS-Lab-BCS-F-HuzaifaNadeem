#include <iostream>
using namespace std;

int main() {
    int size;

    
    cout << "Enter the size of the array: ";
    cin >> size;

   
    int* arr = new int[size];

    
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }

	   
	char choice;
	do {
	    int pos, val;
	
	    
	    while (true) {
	        cout << "Enter position to update (0 to " << size - 1 << "): ";
	        cin >> pos;
	        if (pos >= 0 && pos < size) {
	            break;  
	        }
	        cout << "Invalid position. Try again.\n";
	    }
	
	    cout << "Enter value: ";
	    cin >> val;
	
	    arr[pos] = val;
	
	    cout << "Do you want to update another position? (y/n): ";
	    cin >> choice;
	} while (choice == 'y' || choice == 'Y');

    
    cout << "Final array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    delete[] arr;

    return 0;
}
