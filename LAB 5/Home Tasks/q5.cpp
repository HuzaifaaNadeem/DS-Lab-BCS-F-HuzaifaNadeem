#include <iostream>
using namespace std;

const int N = 9;

bool valid(int board[N][N], int r, int c, int val) {
    for (int i = 0; i < N; i++) {
        if (board[r][i] == val || board[i][c] == val)
            return false;
    }
    int sr = r - r % 3, sc = c - c % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[sr + i][sc + j] == val)
                return false;
        }
    }
    return true;
}

bool emptyCell(int board[N][N], int &r, int &c) {
    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
            if (board[r][c] == 0)
                return true;
        }
    }
    return false;
}

bool solve(int board[N][N]) {
    int r, c;
    if (!emptyCell(board, r, c))
        return true;
    for (int num = 1; num <= 9; num++) {
        if (valid(board, r, c, num)) {
            board[r][c] = num;
            if (solve(board))
                return true;
            board[r][c] = 0;
        }
    }
    return false;
}

void print(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int board[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if (solve(board))
        print(board);
    else
        cout << "No solution" << endl;

    return 0;
}
