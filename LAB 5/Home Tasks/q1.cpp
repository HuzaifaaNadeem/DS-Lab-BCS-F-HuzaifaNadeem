#include <iostream>
using namespace std;

int factorial(int x) {
    if (x == 0 || x == 1)
        return 1;
    return x * factorial(x - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << n << " is " << factorial(n) << endl;
    }

    return 0;
}
