#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int N;
int people[11], visited[11], comp[11], ret = INF;
vector<int> adj[11];

pair<int, int> dfs(int idx, int state) {
    visited[idx] = 1;
    pair<int, int> ret = make_pair(1, people[idx]);
    for(int i = 0; i < adj[idx].size(); i++) {
        int there = adj[idx][i];
        if(comp[there] != state) continue;
        if(visited[there]) continue;
        pair<int, int> tmp = dfs(there, state);
        ret.first += tmp.first;
        ret.second += tmp.second;
    }
    return ret;
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> people[i];
    }

    for(int i = 1; i <= N; i++) {
        int m;
        cin >> m;
        for(int j = 0; j < m; j++) {
            int num;
            cin >> num;
            adj[i].push_back(num);
            adj[num].push_back(i);
        }
    }

    for(int i = 1; i < (1 << N) - 1; i++) {
        fill(comp, comp + 11, 0);
        fill(visited, visited + 11, 0);

        int idx1 = -1, idx2 = -1;

        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                comp[j + 1] = 1;
                idx1 = j + 1;
            } else idx2 = j + 1;
        }

        pair<int, int> comp1 = dfs(idx1, 1);
        pair<int, int> comp2 = dfs(idx2, 0);
        if(comp1.first + comp2.first == N) ret = min(ret, abs(comp1.second - comp2.second));
    }

    cout << (ret == INF ? -1 : ret);

    return 0;
}