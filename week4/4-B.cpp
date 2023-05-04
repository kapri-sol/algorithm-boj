#include <iostream>
#include <string>

using namespace std;

const int INF = 987654321;

int N, coin[21], ret = INF;

void dfs(int n) {
    if(n == N + 1) {
        int sum = 0;
        for(int i = 1; i < (1 << N); i*=2) {
            int cnt = 0;
            for(int j = 1; j <= N; j++) if(coin[j] & i) cnt++;
            sum += min(cnt, N - cnt);
        }
        ret = min(ret, sum);
        return;
    }

    dfs(n + 1);
    coin[n] = ~coin[n];
    dfs(n + 1);
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++){
        string s;
        cin >> s;
        int value = 1;
        for(int j = 0; j < N; j++) {
            if (s[j] == 'T')
                coin[i] |= value;
            value *= 2;
        }
    }

    dfs(1);
    cout << ret;
    return 0;
}