#include <iostream>
using namespace std;

class SafePointer {
    int* ptr;
public:
    SafePointer() {
        ptr = new int;
    }

    void setValue(int value) {
        *ptr = value;
    }

    int getValue() {
        return *ptr;
    }

    void release() {
        delete ptr;
        ptr = nullptr;
    }

    ~SafePointer() {
        if (ptr != nullptr) {
            delete ptr;
        }
    }
};

int main() {
    const int students = 5;
    SafePointer marks[students];

    cout << "Enter marks of " << students << " students:" << endl;
    for (int i = 0; i < students; i++) {
        int mark;
        cout << "Student " << i + 1 << ": ";
        cin >> mark;
        marks[i].setValue(mark);
    }

    cout << endl << "Marks of students:" << endl;
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ": " << marks[i].getValue() << endl;
    }

    for (int i = 0; i < students; i++) {
        marks[i].release();
    }

    return 0;
}
