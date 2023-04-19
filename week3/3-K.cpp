#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int R, C;
int map[1500][1500], visitedWater[1500][1500], visitedSwan[1500][1500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int> > v;
queue<pair<int, int> > water, swan;

void melt() {
    queue<pair<int, int> > tmp;
    while(water.size()) {
        tmp.push(water.front());
        water.pop();
    }
    while(tmp.size()) {
        int x = tmp.front().first;
        int y = tmp.front().second;

        tmp.pop();

        for(int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(visitedWater[nx][ny]) continue;
            visitedWater[nx][ny] = 1;
            if(map[nx][ny]) {
                map[nx][ny] = 0;
                water.push(make_pair(nx, ny));
            } else tmp.push(make_pair(nx, ny));
        }
    }
}

int move() {
    int day = 0;
    swan.push(make_pair(v[0].first, v[0].second));
    visitedSwan[v[0].first][v[0].second] = 1;

    while(swan.size()) {
        queue<pair<int, int> > tmp;
        while(swan.size()) {
            tmp.push(swan.front());
            swan.pop();
        }

        while(tmp.size()) {
            int x = tmp.front().first;
            int y = tmp.front().second;
            tmp.pop();

            if(x == v[1].first && y ==v[1].second) return day;

            for(int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if(visitedSwan[nx][ny]) continue;

                visitedSwan[nx][ny] = 1;
                if(map[nx][ny]) swan.push(make_pair(nx, ny));
                else tmp.push(make_pair(nx, ny));
            }
        }
        melt();
        day++;
    }
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < C; j++) {
            if(s[j] == 'X') map[i][j] = 1;
            if(s[j] == 'L') v.push_back(make_pair(i, j));
            if(s[j] == '.' || s[j] == 'L') {
                water.push(make_pair(i, j));
                visitedWater[i][j] = 1;
            }
        }
    }

    cout << move();

    return 0;
}