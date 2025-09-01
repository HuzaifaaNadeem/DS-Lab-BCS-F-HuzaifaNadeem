#include <iostream>
#include <limits>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter number of readings per day: ";
    cin >> m;

    double** temp = new double*[n];
    for (int i = 0; i < n; i++)
        temp[i] = new double[m];

    cout << "Enter temperature readings:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> temp[i][j];

    double* avg = new double[n];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++)
            sum += temp[i][j];
        avg[i] = sum / m;
    }

    for (int i = 0; i < n; i++)
        cout << "Day " << i + 1 << " average: " << avg[i] << endl;

    double hottest = numeric_limits<double>::min(), coldest = numeric_limits<double>::max();
    int hotDay = -1, coldDay = -1;
    for (int i = 0; i < n; i++) {
        if (avg[i] > hottest) { hottest = avg[i]; hotDay = i; }
        if (avg[i] < coldest) { coldest = avg[i]; coldDay = i; }
    }

    cout << "Hottest day: Day " << hotDay + 1 << " with avg " << hottest << endl;
    cout << "Coldest day: Day " << coldDay + 1 << " with avg " << coldest << endl;

    for (int i = 0; i < n; i++)
        delete[] temp[i];
    delete[] temp;
    delete[] avg;

    return 0;
}
