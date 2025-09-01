#include <iostream>
using namespace std;

int main() {
    int months;
    cout << "How many months of expenses do you want to track? ";
    cin >> months;

    double* expenses = new double[months];

    cout << "Enter your expenses for " << months << " months:" << endl;
    for (int i = 0; i < months; i++) {
        cout << "Month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    char choice;
    cout << "Would you like to add more months? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int extra;
        cout << "How many additional months do you want to add? ";
        cin >> extra;

        double* new_expenses = new double[months + extra];
        for (int i = 0; i < months; i++) {
            new_expenses[i] = expenses[i];
        }

        delete[] expenses;
        expenses = new_expenses;

        cout << "Enter expenses for the next " << extra << " months:" << endl;
        for (int i = months; i < months + extra; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> expenses[i];
        }

        months += extra;
    }

    double total = 0;
    for (int i = 0; i < months; i++) {
        total += expenses[i];
    }

    double average = total / months;

    cout << endl << "Total Expenses: " << total << endl;
    cout << "Average Expenses: " << average << endl;

    delete[] expenses;
    return 0;
}
