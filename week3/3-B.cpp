#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
int N, M;
int map[50][50];
int visited[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    int dist = 0;

    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int x = front.first;
        int y = front.second;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(visited[nx][ny] || map[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + 1;
            dist = max(dist, visited[nx][ny]);
            q.push(make_pair(nx, ny));
        }
    }

    memset(visited, 0, sizeof(visited));

    return dist;
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < M; j++) {
            if(s[j] == 'W') map[i][j] = 1;
        }
    }

    int mx = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0)
                mx = max(mx, bfs(i, j));
        }
    }

    cout << mx - 1;

    return 0;
}