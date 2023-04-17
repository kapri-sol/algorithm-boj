#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, L, R;
int map[50][50];
int visited[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt, total, day;

vector<pair<int, int> > v;

bool check(int a, int b) {
    int abs = max(a, b) - min(a, b);
    return L <= abs && abs <= R;
}

void dfs(int x, int y) {
    visited[x][y] = 1;
    cnt++;
    total += map[x][y];
    v.push_back(make_pair(x, y));

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(visited[nx][ny] || !check(map[x][y], map[nx][ny])) continue;

        dfs(nx, ny);
    }
}

int main() {
    cin >> N >> L >> R;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];

    while(true) {
        bool flag = false;

        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited[i][j]) {
                    cnt = 0;
                    total = 0;
                    v.clear();

                    dfs(i, j);

                    if(cnt > 1) {
                        flag = true;
                        for(int k = 0; k < v.size(); k++) {
                            map[v[k].first][v[k].second] = total / cnt;
                        }
                    } else {
                        visited[i][j] = 0;
                    }
                }
            }
        }

        if(!flag) break;
        else day++;
    }

    cout << day;
    return 0;
}