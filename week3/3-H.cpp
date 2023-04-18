#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int mn;
const int MAX = 100002 * 2;
int visited[MAX], preved[MAX];

void bfs() {
    queue<int> q;

    q.push(N);
    visited[N] = 1;

    while(q.size()) {
        int current = q.front();
        q.pop();

        if(current == K) {
            mn = visited[current];
            break;
        }

        int d[3] = {current + 1, current - 1, current * 2};

        for(int i = 0; i < 3; i++) {
            int next = d[i];
            if(next < 0 || next >= MAX) continue;
            if(visited[next]) continue;
            visited[next] = visited[current] + 1;
            preved[next] = current;
            q.push(next);
        }
    }

    vector<int> trace;

    for(int i = K; i != N; i = preved[i])
        trace.push_back(i);

    trace.push_back(N);
    reverse(trace.begin(), trace.end());

    cout << mn - 1 << "\n";

    for(int i = 0; i < trace.size(); i++) cout << trace[i] << " ";

    cout << "\n";
}

int main() {
    cin >> N >> K;

    bfs();

    return 0;
}