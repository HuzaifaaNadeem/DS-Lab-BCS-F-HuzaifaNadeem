#include <iostream>
using namespace std;

class Box {
private:
    int* data;

public:
    Box(int value = 0) {
        data = new int(value);
        cout << "Constructor called, value = " << *data << endl;
    }

    ~Box() {
        cout << "Destructor called, deleting value = " << *data << endl;
        delete data;
    }

    Box(const Box& other) {
        data = new int(*other.data);
        cout << "Copy Constructor called, deep copied value = " << *data << endl;
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
            cout << "Copy Assignment called, deep copied value = " << *data << endl;
        }
        return *this;
    }

    int getValue() const {
        return *data;
    }

    void setValue(int value) {
        *data = value;
    }
};

class ShallowBox {
public:
    int* data;

    ShallowBox(int value) {
        data = new int(value);
        cout << "Constructor (ShallowBox), value = " << *data << endl;
    }

    void setValue(int value) {
        *data = value;
    }

    ~ShallowBox() {
        cout << "Destructor (ShallowBox), deleting value = " << *data << endl;
        delete data;
    }
};

int main() {
    cout << "Deep Copy" << endl;
    Box boxA(10);
    Box boxB = boxA;

    boxB.setValue(20);
    cout << "boxA value = " << boxA.getValue() << endl;
    cout << "boxB value = " << boxB.getValue() << endl;

    Box boxC;
    boxC = boxA;
    boxC.setValue(30);

    cout << "boxA value = " << boxA.getValue() << endl;
    cout << "boxC value = " << boxC.getValue() << endl;

    cout << "Shallow Copy" << endl;
    ShallowBox shallowA(100);
    ShallowBox shallowB = shallowA;

    shallowB.setValue(200);

    cout << "shallowA value = " << *shallowA.data << endl;
    cout << "shallowB value = " << *shallowB.data << endl;

    return 0;
}

/*
In deep copy, every object gets its own memory, so when one object is copied, a new memory is created and the value is stored separately.
This means changes in one object do not affect the other, and no errors occur since each object manages its own memory.
On the other hand, in shallow copy only the pointer is copied, not the actual data. Both objects end up sharing the same memory, so if one is changed, the other also changes. 
The main problem is that when both objects are destroyed, they try to delete the same memory, which can cause a runtime crash.
*/


