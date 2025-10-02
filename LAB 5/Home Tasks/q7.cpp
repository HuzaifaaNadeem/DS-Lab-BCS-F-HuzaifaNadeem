#include <iostream>
using namespace std;

bool safe(int **board, int n, int r, int c) {
    for (int i = 0; i < r; i++) {
        if (board[i][c] == 1)
            return false;
    }
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

void show(int **board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                cout << "Q";
            else
                cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int **board, int n, int r) {
    if (r == n) {
        show(board, n);
        return;
    }
    for (int c = 0; c < n; c++) {
        if (safe(board, n, r, c)) {
            board[r][c] = 1;
            solve(board, n, r + 1);
            board[r][c] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    int **board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    }

    solve(board, n, 0);

    for (int i = 0; i < n; i++)
        delete[] board[i];
    delete[] board;

    return 0;
}
