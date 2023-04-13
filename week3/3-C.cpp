#include <iostream>

using namespace std;

int N, L, R;
int map[50][50];
int visited[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt;

int check(int a, int b) {
    return max(a, b) - min(a, b);
}

int dfs(int x, int y) {
    int total = 1;

    visited[x][y] = cnt;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        int ads = check(map[x][y], map[nx][ny]);
        if(visited[nx][ny] ||  ads < L || ads > R) continue;

        total += dfs(nx, ny);
    }

    return total;
}

int main() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    return 0;
}