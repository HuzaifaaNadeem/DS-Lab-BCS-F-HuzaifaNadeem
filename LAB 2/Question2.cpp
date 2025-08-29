#include <iostream>
using namespace std;

int main() {
    int rows, cols;

  
    cout << "Enter number of benches (rows): ";
    cin >> rows;
    cout << "Enter number of seats per bench (columns): ";
    cin >> cols;

    
    int** seatingChart = new int*[rows];
    for (int i = 0; i < rows; i++) {
        seatingChart[i] = new int[cols];
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            seatingChart[i][j] = 0;
        }
    }

    
    char choice;
    do {
        int r, c;
        
        while (true) {
            cout << "Enter bench number (0 to " << rows - 1 << "): ";
            cin >> r;
            if (r >= 0 && r < rows) break;
            cout << "Invalid bench number. Try again.\n";
        }
        while (true) {
            cout << "Enter seat number (0 to " << cols - 1 << "): ";
            cin >> c;
            if (c >= 0 && c < cols) break;
            cout << "Invalid seat number. Try again.\n";
        }

        seatingChart[r][c] = 1;

        cout << "Do you want to fill another seat? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    
    cout << "\nFinal seating chart (0 = empty, 1 = occupied):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << seatingChart[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < rows; i++) {
        delete[] seatingChart[i];
    }
    delete[] seatingChart;

    return 0;
}

