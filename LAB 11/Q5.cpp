#include <iostream>
using namespace std;

const int N = 5;

void displayAdjList(int adjList[N][N], int sizes[N]) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ":";
        for (int j = 0; j < sizes[i]; j++) {
            cout << adjList[i][j];
            if (j < sizes[i] - 1) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void displayMatrix(int matrix[N][N]) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j];
            if (j < N - 1) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(int start, int matrix[N][N]) {
    cout << "BFS:" << endl;

    int visited[N] = {0};
    int queue[100];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        cout << node + 1;
        
        if (front < rear) cout << " ";

        for (int i = 0; i < N; i++) {
            if (matrix[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    cout << endl << endl;
}

void DFSUtil(int node, int visited[N], int matrix[N][N]) {
    visited[node] = 1;
    cout << node + 1;

    for (int i = 0; i < N; i++) {
        if (matrix[node][i] == 1 && !visited[i]) {
            cout << " ";
            DFSUtil(i, visited, matrix);
        }
    }
}

void DFS(int start, int matrix[N][N]) {
    cout << "DFS:" << endl;
    int visited[N] = {0};
    DFSUtil(start, visited, matrix);
    cout << endl << endl;
}

int main() {
    int matrix[N][N] = {0};

    int edges[][2] = {
        {1, 4},
        {2, 4}, {2, 5},
        {3, 5},
        {4, 5}
    };

    int E = 5;

    for (int i = 0; i < E; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    int adjList[N][N];
    int sizes[N] = {0};

    for (int i = 0; i < N; i++) {
        sizes[i] = 0;
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1) {
                adjList[i][sizes[i]++] = j + 1;
            }
        }
    }

    displayAdjList(adjList, sizes);
    displayMatrix(matrix);

    BFS(0, matrix);
    DFS(0, matrix);

    return 0;
}
