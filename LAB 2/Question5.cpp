#include <iostream>
using namespace std;

double** createMatrix(int rows, int cols) {
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
    }
    return matrix;
}

void inputMatrix(double** matrix, int rows, int cols, const string& name) {
    cout << "Enter values for " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << name << " [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(double** matrix, int rows, int cols, const string& name) {
    cout << endl << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

double** addMatrices(double** a, double** b, int rows, int cols) {
    double** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

double** subtractMatrices(double** a, double** b, int rows, int cols) {
    double** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    double** matrixA = createMatrix(rows, cols);
    double** matrixB = createMatrix(rows, cols);

    inputMatrix(matrixA, rows, cols, "Matrix A");
    inputMatrix(matrixB, rows, cols, "Matrix B");

    double** sum = addMatrices(matrixA, matrixB, rows, cols);
    double** difference = subtractMatrices(matrixA, matrixB, rows, cols);

    printMatrix(matrixA, rows, cols, "Matrix A");
    printMatrix(matrixB, rows, cols, "Matrix B");
    printMatrix(sum, rows, cols, "A + B");
    printMatrix(difference, rows, cols, "A - B");

    freeMatrix(matrixA, rows);
    freeMatrix(matrixB, rows);
    freeMatrix(sum, rows);
    freeMatrix(difference, rows);

    return 0;
}
