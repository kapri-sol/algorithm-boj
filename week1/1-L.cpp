#include <iostream>

using namespace std;

int N, M;
int iron[15000];
int cnt = 0;

int main() {
    cin >> N;
    cin >> M;

    for(int i = 0; i < N; i++) cin >> iron[i];
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(iron[i] + iron[j] == M) cnt++;
        }
    }
    cout << cnt;
    return 0;
}