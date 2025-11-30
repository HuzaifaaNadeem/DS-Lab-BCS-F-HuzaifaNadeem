#include <iostream>
using namespace std;

const int S = 6;
const int BIG = 99999;

int main() {
    int g[S][S] = {
        {0,4,0,8,0,0},
        {4,0,9,0,0,0},
        {0,9,0,6,14,0},
        {8,0,6,0,0,4},
        {0,0,14,0,0,3},
        {0,0,0,4,3,0}
    };

    int dist[S];
    int done[S] = {0};
    int prev[S];

    for (int i = 0; i < S; i++) {
        dist[i] = BIG;
        prev[i] = -1;
    }

    int start = 1;
    int goal = 4;
    dist[start] = 0;

    for (int step = 0; step < S - 1; step++) {
        int best = BIG, pick = -1;
        for (int i = 0; i < S; i++) {
            if (!done[i] && dist[i] < best) {
                best = dist[i];
                pick = i;
            }
        }

        done[pick] = 1;

        for (int j = 0; j < S; j++) {
            if (!done[j] && g[pick][j] > 0 && dist[pick] + g[pick][j] < dist[j]) {
                dist[j] = dist[pick] + g[pick][j];
                prev[j] = pick;
            }
        }
    }

    cout << "Shortest Distance from B to E: " << dist[goal] << endl;

    int path[S];
    int len = 0;
    int cur = goal;

    while (cur != -1) {
        path[len++] = cur;
        cur = prev[cur];
    }

    cout << "Path: ";
    for (int i = len - 1; i >= 0; i--) {
        cout << char('A' + path[i]);
        if (i > 0) cout << "->";
    }
    cout << endl;

    return 0;
}
