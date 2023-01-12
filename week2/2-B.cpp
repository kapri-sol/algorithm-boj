#include <iostream>

using namespace std;

int map[50][50];
int visited[50][50];
int T, M, N, K;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt;
string ret;
// 0 0 0 0 1
// 0 0 0 0 0
// 0 0 0 1 0
//
//
void dfs(int x, int y) {
    visited[x][y] = cnt;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(!map[nx][ny] || visited[nx][ny]) continue;

        dfs(nx, ny);
    }
}
int main() {
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        fill(&map[0][0], &map[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for(int k = 0; k < K; k++){
            int m, n;
            cin >> m >> n;
            map[n][m] = 1;
        }
        cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(!map[i][j] || visited[i][j]) continue;
                cnt++;
                dfs(i, j);
            }
        }
        ret += to_string(cnt) + "\n";
    }
    cout << ret;
    return 0;
}