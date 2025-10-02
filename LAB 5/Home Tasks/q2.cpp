#include <iostream>
using namespace std;

void showNumbers(int x) {
    if (x == 0)
        return;
    cout << x << " ";
    showNumbers(x - 1);
}

void alpha(int x);
void beta(int x);

void alpha(int x) {
    if (x <= 0)
        return;
    cout << "A: " << x << endl;
    beta(x - 1);
}

void beta(int x) {
    if (x <= 0)
        return;
    cout << "B: " << x << endl;
    alpha(x - 1);
}

int main() {
    int option, value;
    cout << "1. Direct Recursion" << endl;
    cout << "2. Indirect Recursion" << endl;
    cout << "Enter choice: ";
    cin >> option;

    cout << "Enter number: ";
    cin >> value;

    if (option == 1)
        showNumbers(value);
    else if (option == 2)
        alpha(value);
    else
        cout << "Invalid choice" << endl;

    return 0;
}
