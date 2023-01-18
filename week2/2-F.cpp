#include <iostream>

using namespace std;

int N, M, J;
int apple[20];
int L = 1;
int R;
int totalCnt;

void toLeft(int cnt) {
    L -= cnt;
    R -= cnt;
    totalCnt += cnt;
}

void toRight(int cnt) {
    L += cnt;
    R += cnt;
    totalCnt += cnt;
}

int main() {
    cin >> N >> M >> J;

    R = L + M - 1;

    for(int i = 0; i < J; i++)
        cin >> apple[i];


    for(int i = 0; i < J; i++) {
        if(L <= apple[i] && apple[i] <= R) continue;
        else if(apple[i] < L) toLeft(L - apple[i]);
        else if(apple[i] > R) toRight(apple[i] - R);
    }
    cout << totalCnt;
    return 0;
}