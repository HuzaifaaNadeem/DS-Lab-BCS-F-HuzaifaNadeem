#include <iostream>
using namespace std;

void printNumbers(int n) {
    if (n <= 0) return;  
    cout << n << " ";
    printNumbers(n - 1);
}


void functionB(int n);

void functionA(int n) {
    if (n <= 0) return;  
    cout << n << " ";
    functionB(n - 1);
}

void functionB(int n) {
    if (n <= 0) return; 
    cout << n << " ";
    functionA(n - 1);
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;
    cout << "Direct recursion output: ";
    printNumbers(n);
    cout << "\n\n";

    cout << "Indirect recursion output: ";
    functionA(n);
    cout << endl;

    return 0;
}
