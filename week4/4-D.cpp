#include <iostream>
#include <string>

using namespace std;

int R, C, map[20][20], ret;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve(int x, int y, int num, int cnt) {
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
        int next = (1 << (int)(map[nx][ny] - 'A'));
        if((num & next) == 0) solve(nx, ny, num | next, cnt + 1);
    }
    return;
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < C; j++) {
            map[i][j] = s[j];
        }
    }
    solve(0, 0, 1 << (int)(map[0][0] - 'A'), 1);
    cout << ret;
    return 0;
}