#include <iostream>
#include <string>
#include <vector>

using namespace std;

int R, C;
int map[20][20], visited[20][20];
int alphabet[26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int mx;

void move(int x, int y, int cnt) {
    mx = max(mx, cnt);

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <0 || ny <0 || nx >= R || ny >= C || visited[nx][ny]) continue;
        if(alphabet[map[nx][ny]]) continue;
        visited[nx][ny] = 1;
        alphabet[map[nx][ny]] = 1;
        move(nx, ny, cnt + 1);
        visited[nx][ny] = 0;
        alphabet[map[nx][ny]] = 0;
    }
}

int main() {
    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < C; j++) map[i][j] = s[j] - 'A';
    }

    visited[0][0] = 1;
    alphabet[map[0][0]] = 1;
    move(0, 0, 1);

    cout << mx;
    return 0;
}
