#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[100][100];
int visited[100][100];
int dx[4] = {0 , -1, 0, 1};
int dy[4] = {1, 0 , -1, 0};

int main() {
    queue<pair<int, int> > q;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    visited[0][0] = 1;
    q.push(pair<int, int>(0, 0));
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        if(current.first == N -1 && current.second == M - 1) {
            cout << visited[current.first][current.second] << "\n";
            break;
        }
        for(int i = 0; i < 4; i++) {
            int nx =  current.first + dx[i];
            int ny = current.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(!map[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = visited[current.first][current.second] + 1;
            q.push(pair<int, int>(nx, ny));
        }
    }
    return 0;
}