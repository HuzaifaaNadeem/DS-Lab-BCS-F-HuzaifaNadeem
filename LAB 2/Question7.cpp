#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;

 
    vector<vector<int>> salaries(departments);

    for (int i = 0; i < departments; i++) {
        int employees;
        cout << "Enter number of employees in department " << i + 1 << ": ";
        cin >> employees;

        salaries[i].resize(employees);
        cout << "Enter salaries for department " << i + 1 << ":\n";
        for (int j = 0; j < employees; j++) {
            cin >> salaries[i][j];
        }
    }

    cout << "\n--- Results ---\n";

    for (int i = 0; i < departments; i++) {
        int maxSalary = numeric_limits<int>::min();
        for (int sal : salaries[i]) {
            if (sal > maxSalary) maxSalary = sal;
        }
        cout << "Highest salary in department " << i + 1 << ": " << maxSalary << endl;
    }

    double maxAvg = -1;
    int maxDept = -1;

    for (int i = 0; i < departments; i++) {
        double sum = 0;
        for (int sal : salaries[i]) {
            sum += sal;
        }
        double avg = sum / salaries[i].size();
        if (avg > maxAvg) {
            maxAvg = avg;
            maxDept = i;
        }
    }

    cout << "Department " << maxDept + 1 << " has the maximum average salary: " << maxAvg << endl;

    return 0;
}
