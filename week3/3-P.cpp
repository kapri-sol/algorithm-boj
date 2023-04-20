#include <iostream>

using namespace std;

int N, G[10][10], visited[10][10];
int mn = 200 * 10 * 10 + 1;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool check(int x, int y) {
    if(visited[x][y]) return false;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) return false;
    }

    return true;
}

int setFlower(int x, int y) {
    visited[x][y] = 1;
   int price = G[x][y];

   for(int i = 0; i < 4; i++) {
       int nx = x + dx[i];
       int ny = y + dy[i];
       visited[nx][ny] = 1;
       price += G[nx][ny];
   }

    return price;
}

void unsetFlower(int x, int y) {
    visited[x][y] = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = 0;
    }
}

void dfs(int cnt, int price) {
    if(cnt == 3) {
        mn = min(mn, price);
        return;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(check(i, j)) {
                dfs(cnt + 1, price + setFlower(i, j));
                unsetFlower(i, j);
            }
        }
    }
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> G[i][j];

    dfs(0, 0);

    cout << mn;

    return 0;
}