#include <iostream>
using namespace std;

const int N = 5;

bool canMove(int maze[N][N], int r, int c, bool vis[N][N]) {
    return (r >= 0 && r < N && c >= 0 && c < N && maze[r][c] == 1 && !vis[r][c]);
}

bool path(int maze[N][N], int r, int c, int sol[N][N], bool vis[N][N]) {
    if (r == N - 1 && c == N - 1) {
        sol[r][c] = 1;
        return true;
    }
    if (canMove(maze, r, c, vis)) {
        vis[r][c] = true;
        sol[r][c] = 1;
        if (path(maze, r + 1, c, sol, vis)) return true;
        if (path(maze, r, c + 1, sol, vis)) return true;
        if (path(maze, r - 1, c, sol, vis)) return true;
        if (path(maze, r, c - 1, sol, vis)) return true;
        sol[r][c] = 0;
        vis[r][c] = false;
    }
    return false;
}

void print(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int maze[N][N] = {
        {1,0,0,0,0},
        {1,1,0,1,1},
        {0,1,0,0,1},
        {1,1,1,1,0},
        {0,0,0,1,1}
    };

    int sol[N][N] = {0};
    bool vis[N][N] = {false};

    if (path(maze, 0, 0, sol, vis))
        print(sol);
    else
        cout << "No path" << endl;

    return 0;
}
