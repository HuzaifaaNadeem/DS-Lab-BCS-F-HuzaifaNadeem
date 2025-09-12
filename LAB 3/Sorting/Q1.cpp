//Sorting Q1

#include <iostream>

using namespace std;

int main(){
	int arr[] = {5, 1, 3, 6, 2, 9, 7, 4, 8, 10};
	int sizeArr = sizeof(arr)/sizeof(arr[0]);
	
	cout << "Initial Array: ";
	for (int i = 0; i < sizeArr; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	for (int i = 0; i < sizeArr-1; ++i){
		for (int j = 0; j < sizeArr-i-1; ++j){
			if (arr[j] < arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	cout << "Sorted Array: ";
	for (int i = 0; i < sizeArr; i++){
		cout << arr[i] << " ";
	}
}
