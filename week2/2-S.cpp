#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M;
vector<int> trust[10001];
int visited[10001];
int dp[10001];
int maxCnt;

int search(int start) {
    visited[start] = 1;

    int cnt = 1;
    for(int i = 0; i < trust[start].size(); i++) {
        if(visited[trust[start][i]]) continue;
        cnt += search(trust[start][i]);
    }
    return cnt;
}

int main() {
    vector<int> ret;

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int src, dst;
        cin >> dst >> src;
        trust[src].push_back(dst);
    }

    for(int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        dp[i] = search(i);
        maxCnt = max(dp[i], maxCnt);
    }

    for(int i = 1; i <= N; i++) {
        if(dp[i] == maxCnt) ret.push_back(i);
    }

    sort(ret.begin(), ret.end());

    for(int i = 0; i < ret.size(); i++) cout << ret[i] << " ";

    return 0;
}