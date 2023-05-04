#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int map[100][100], reverseMap[100][100], ret;

void solve(int m[100][100]) {
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        int j;
        for(j = 0; j < N - 1; j++) {
            if(m[i][j] == m[i][j+1]) cnt++;
            else if(m[i][j] + 1 == m[i][j + 1] && cnt >= L) cnt = 1;
            else if(m[i][j] - 1 == m[i][j + 1] && cnt >= 0) cnt = -L + 1;
            else break;
        }
        if(j == N - 1 && cnt >= 0) ret++;
    }
}

int main() {
    cin >> N >> L;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            reverseMap[j][i] = map[i][j];
        }
    }


    solve(map);
    solve(reverseMap);
    cout << ret;
    return 0;
}