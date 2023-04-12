#include <iostream>
#include <string>

using namespace std;

int R, C, K;
int map[5][5];
int visited[5][5];
int cnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int k) {
    if(k > K) return;
    if(x == R-1 && y == C-1) {
        if(k == K) cnt++;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if(visited[nx][ny] || map[nx][ny] == 1) continue;
        visited[nx][ny] = 1;
        dfs(nx, ny, k +1);
        visited[nx][ny] = 0;
    }
}

int main() {
    cin >> R >> C >> K;

    for(int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < C; j++) {
            if(s[j] == 'T') {
                map[R-i-1][j] = 1;
            }
        }
    }

    visited[0][0] = 1;
    dfs(0,0, 1);

    cout << cnt;
    return 0;
}