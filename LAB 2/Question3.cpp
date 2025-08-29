#include <iostream>
using namespace std;

int main() {
    int students;
    cout << "How many students are there? ";
    cin >> students;

    int** marks = new int*[students];   
    int* courses = new int[students];   
    for (int i = 0; i < students; i++) {
        cout << "\nEnter number of courses for student " << i + 1 << ": ";
        cin >> courses[i];

        marks[i] = new int[courses[i]];  

        cout << "Enter marks for " << courses[i] << " courses:\n";
        for (int j = 0; j < courses[i]; j++) {
            cout << "Course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\n--- Average Marks of Students ---\n";
    for (int i = 0; i < students; i++) {
        int total = 0;
        for (int j = 0; j < courses[i]; j++) {
            total += marks[i][j];
        }
        double average = (double)total / courses[i];
        cout << "Student " << i + 1 << " ? Average = " << average << endl;
    }

    
    for (int i = 0; i < students; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] courses;

    return 0;
}

