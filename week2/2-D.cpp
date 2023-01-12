#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int map[100][100];
int visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt;
vector<int> sum;

void dfs(int x, int y) {
    visited[x][y] = 1;
    sum[cnt]++;
    for(int i = 0; i < 4; i++ ){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(visited[nx][ny] || map[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main() {
    cin >> M >> N >> K;
    for(int k = 0; k < K; k++) {
        int nx, ny, mx, my;
        cin >> nx >> ny >> mx >> my;
        for(int i = nx; i < mx; i++) {
            for(int j = ny; j < my; j++) {
                map[i][j] = 1;
            }
        }
    }



    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j] || map[i][j]) continue;
            sum.push_back(0);
            dfs(i, j);
            cnt++;
        }
    }

    cout << cnt << "\n";

    sort(sum.begin(), sum.end());

    for(int i = 0; i < sum.size(); i++) {
        cout << sum[i] << " ";
    }
    cout << "\n";
    return 0;
}