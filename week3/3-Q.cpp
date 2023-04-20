#include <iostream>
#include <string>

using namespace std;

int R, C, K;
int cnt, map[5][5], visited[5][5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    if(x == 0 && y == C-1 && visited[x][y] == K) cnt++;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny]) continue;
        if(map[nx][ny]) continue;
        visited[nx][ny] = visited[x][y] + 1;
        dfs(nx, ny);
        visited[nx][ny] = 0;
    }
}

int main() {
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < C; j++ ){
            if(s[j] == 'T') map[i][j] = 1;
        }
    }

    visited[R-1][0] = 1;
    dfs(R-1, 0);

    cout << cnt;

    return 0;
}