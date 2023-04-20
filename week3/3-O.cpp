#include <iostream>

using namespace std;

int N, M, H;
int ladder[30][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int mn = 300;

bool check () {
    for(int i = 0; i < N; i++) {
        int start = i;
        for(int j = 0; j < H; j++) {
            if(ladder[j][start]) start++;
            else if(ladder[j][start - 1]) start--;
        }
        if(start != i) return false;
    }

    return true;
}

void dfs(int here, int cnt) {
    if(cnt >= mn || cnt > 3) return;
    if(check()) {
        mn = min(mn, cnt);
        return;
    }

    for(int i = here; i < H; i++) {
        for(int j = 0; j < N; j++) {
            if(ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue;
            ladder[i][j] = 1;
            dfs(i, cnt + 1);
            ladder[i][j] = 0;
        }
    }
}

int main() {
    cin >> N >> M >> H;

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        ladder[x-1][y-1] = 1;
    }

    dfs(0, 0);

    if(mn > 3) mn = -1;

    cout << mn;

    return 0;
}