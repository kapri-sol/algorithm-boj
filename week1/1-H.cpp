#include <iostream>

using namespace std;

int t[100000];
int psum[100000];
int maxSum = -100 * 100000;

int main() {
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> t[i];

    psum[0] = t[0];

    for(int i = 1; i < N; i++) psum[i] = psum[i-1] + t[i];
    for(int i = K-1; i < N; i++) {
        int sum = psum[i] - psum[i-K];
        maxSum = max(sum, maxSum);
    }

    cout << maxSum;

    return 0;
}