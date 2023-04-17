#include <iostream>
#include <queue>

using namespace std;

int N;
int scv[3];
int visited[61][61][61];
struct HPS {
    int a, b, c;
};

queue<HPS> q;

int attack[6][3] = {
        {9, 3, 1},
        {9, 1, 3},
        {3, 1, 9},
        {3, 9, 1},
        {1, 9, 3},
        {1, 3, 9}
};

int bfs(int a, int b, int c) {
    visited[a][b][c] = 1;
    HPS hps = {a, b, c};
    q.push(hps);

    while(q.size()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++) {
            int na = max(0, a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0, c - attack[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            HPS nhps = {na, nb, nc};
            q.push(nhps);
        }
    }
    return visited[0][0][0] - 1;
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> scv[i];

    cout << bfs(scv[0], scv[1], scv[2]);

    return 0;
}