#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[8][8];
int visited[8][8];
int px[4] = {0, 1, 0, -1 };
int py[4] = {1, 0, -1, 0 };
vector<pair<int, int> > walls;
vector<pair<int, int> > virus;
int maxCnt;

void dfs(int n, int m) {
    visited[n][m] = 1;
    for(int i = 0; i < 4; i++) {
        int dx = n + px[i];
        int dy = m + py[i];

        if(dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
        if(visited[dx][dy]) continue;
        if(map[dx][dy] == 1) continue;
        dfs(dx, dy);
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) walls.push_back(make_pair(i, j));
            if(map[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }


    for(int i = 0; i < walls.size(); i++) {
        for(int j = i + 1; j < walls.size(); j++) {
            for(int k = j + 1; k < walls.size(); k++) {
                map[walls[i].first][walls[i].second] = 1;
                map[walls[j].first][walls[j].second] = 1;
                map[walls[k].first][walls[k].second] = 1;

                for(int i = 0; i < virus.size(); i++) {
                    if(visited[virus[i].first][virus[i].second]) continue;
                    dfs(virus[i].first, virus[i].second);
                }

                int cnt = 0;
                for(int n = 0; n < N; n++) {
                    for(int m = 0; m < M; m++) {
                        if(map[n][m] == 0 && !visited[n][m]) cnt++;
                    }
                }
                maxCnt = max(maxCnt, cnt);

                for(int n = 0; n < N; n++) {
                    for(int m = 0; m < M; m++) {
                        visited[n][m] = 0;
                    }
                }

                map[walls[i].first][walls[i].second] = 0;
                map[walls[j].first][walls[j].second] = 0;
                map[walls[k].first][walls[k].second] = 0;
            }
        }
    }

    cout << maxCnt << "\n";
    return 0;
}