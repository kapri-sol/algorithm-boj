#include <iostream>

using namespace std;

int N, M;
int t, lastCnt;
int map[100][100];
int visited[100][100];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int x, int y) {
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(visited[nx][ny] != 0) continue;
        if(map[nx][ny] == 1) {
            visited[nx][ny] = 2;
            continue;
        }
        dfs(nx, ny);
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> map[i][j];


    while(true) {
        int cnt = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(map[i][j] == 1) cnt++;

        dfs(0, 0);

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(visited[i][j] == 2) map[i][j] = 0;

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                visited[i][j] = 0;

        t++;
        if(cnt == 0) break;
        else lastCnt = cnt;
    }

    cout << t - 1 << "\n" << lastCnt;

    return 0;
}