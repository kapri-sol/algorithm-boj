#include <iostream>

using namespace std;

long long A, B, C;

long long go(long long a, long long b) {
    if (b == 1) return a % C;
    long long ret = go(a, b / 2);
    ret = (ret * ret) % C;
    if (b % 2) ret = (ret * a) % C;
    return ret;
}

long long ret = 1;
int main() {
    cin >> A >> B >> C;
    cout << go(A, B);
    return 0;
}
