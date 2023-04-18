#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M, x, y, x2, y2, jump;
int map[300][300], visited[300][300], finded[300][300];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
    queue<pair<int, int> > q;

    q.push(make_pair(x, y));

    while(q.size()) {
        jump++;
        queue<pair<int, int> > tmp;
        while(q.size()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for(int j = 0; j < 4; j++) {
                int nx = cx + dx[j];
                int ny = cy + dy[j];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(visited[nx][ny]) continue;
                visited[nx][ny] = jump;
                if(map[nx][ny]) {
                    map[nx][ny] = 0;
                    tmp.push(make_pair(nx, ny));
                } else q.push(make_pair(nx, ny));
            }
        }
        q = tmp;
    }
    return visited[x2][y2];
}

int main() {
    cin >> N >> M;
    cin >> x >> y >> x2 >> y2;
    x--;
    y--;
    x2--;
    y2--;

    for(int i = 0; i < N; i++) {
        string s;
        cin>> s;
        for(int j = 0; j < M; j++) {
            if(s[j] == '1') map[i][j] = 1;
        }
    }

    cout << bfs();

    return 0;
}