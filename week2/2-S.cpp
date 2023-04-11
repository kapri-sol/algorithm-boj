#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> trust[10001];
int visited[10001];
int dp[10001];
int maxCnt;

int search(int start) {
    if(visited[start]) return dp[start];
    visited[start] = 1;

    int cnt = 0;
    for(int i = 0; i < trust[start].size(); i++) {
        cnt += 1 + search(trust[start][i]);
    }
    dp[start] = cnt;
    maxCnt = max(cnt, maxCnt);
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
        if(trust[i].size()) search(i);
    }


    for(int i = 1; i <= N; i++) {
        if(dp[i] == maxCnt) ret.push_back(i);
    }

    sort(ret.begin(), ret.end());

    for(int i = 0; i < ret.size(); i++) cout << ret[i] << " ";

    return 0;
}