#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int R, C;
int map[1000][1000];
int visited[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    cin >> R >> C;

    queue<pair<int, int> > q;
    vector<pair<int, int> > v;

    for(int i = 0; i < R; i++){
        string s;
        cin >> s;
        for(int j = 0; j < C; j++) {
            if(s[j] == '#') map[i][j] = 1;
            if(s[j] == 'J') {
                map[i][j] = 2;
                q.push(make_pair(i, j));
            }
            if(s[j] == 'F') {
                map[i][j] = 3;
                v.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0; i < v.size(); i++) q.push(v[i]);

    int cnt = 0;

    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        int x = front.first;
        int y = front.second;
        bool isFire = map[x][y] == 3;

        if(!isFire) {
            if(x == 0 || y == 0 || x == R-1 || y == C-1) {
                cnt = visited[x][y] + 1;
                break;
            }
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(isFire) {
                if(map[nx][ny] == 1 || map[nx][ny] == 3) continue;

                map[nx][ny] = 3;
                q.push(make_pair(nx, ny));
                continue;
            }
            if(map[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    if(cnt) cout << cnt;
    else cout << "IMPOSSIBLE";

    return 0;
}