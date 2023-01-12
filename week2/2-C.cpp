#include <iostream>

using namespace std;

int N;
int map[100][100];
int visited[100][100];
int depth, cnt, maxCnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(visited[nx][ny] || map[nx][ny] < depth) continue;
        dfs(nx, ny);
    }
}

int main() {
    cin >> N;
    for(int i = 0; i< N; i++)
        for(int j = 0; j< N; j++)
            cin >> map[i][j];

    for(int k = 1; k <= 100; k++) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                visited[i][j] = 0;

        depth = k;
        cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(map[i][j] < k || visited[i][j]) continue;
                cnt++;
                dfs(i, j);
            }
        }
        maxCnt = max(maxCnt, cnt);
    }
    cout << maxCnt << "\n";
    return 0;
}