#include <iostream>
#include <queue>

using namespace std;

int N, K;
const int MAX = 500001;
int visited[2][MAX+4];
int cnt;

int bfs() {
    if(N == K) {
        return 1;
    }

    queue<int> q;
    visited[0][N] = 1;
    q.push(N);
    while(q.size()) {
        K += cnt;
        if(K >= MAX) return -1;

        if(visited[cnt % 2][K]) {
            return cnt - 1;
        }
        int qSize = q.size();

        for(int i = 0; i < qSize; i++) {
            int current = q.front();
            q.pop();
            int d[3] = {current - 1, current + 1, 2 * current};

            for(int j = 0; j < 3; j++) {
                int next = d[j];
                if(next < 0 || next >= MAX) continue;
                if(visited[cnt%2][next]) continue;
                visited[cnt % 2][next] = visited[(cnt + 1) % 2][next] + 1;
                if(next == K) {
                    return cnt;
                }
                q.push(next);
            }
        }
        cnt++;
    }

    return -1;
}

int main() {
    cin >> N >> K;

    cout << bfs();
    return 0;
}