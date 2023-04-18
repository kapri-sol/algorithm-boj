#include <iostream>
#include <queue>

using namespace std;
int N, K;
const int MAX = 100000;
int visited[MAX+4];
long long cnt[MAX+4];

void bfs() {
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    cnt[N] = 1;

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        if(current == K) {
            continue;
        }

        int d[3] = {current - 1, current + 1, current * 2};

        for(int i = 0; i < 3; i++) {
            int next = d[i];
            if(next < 0 || next > 100000) continue;
            if(!visited[next]) {
                visited[next] = visited[current] + 1;
                cnt[next] += cnt[current];
                q.push(next);
            } else if(visited[next] == visited[current] + 1) cnt[next] += cnt[current];
        }
    }
}

int main() {
    cin >> N >> K;

    if(N == K) {
        cout << "0\n1";
        return 0;
    }
    bfs();
    cout << visited[K] - 1  << "\n" << cnt[K];
    return 0;
}