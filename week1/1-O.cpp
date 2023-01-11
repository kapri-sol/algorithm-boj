#include <iostream>

using namespace std;

int main() {
    int num;
    while(scanf("%d", &num) != EOF) {
        long long acc = 1;
        int cnt = 1;
        while(true) {
            if(acc % num == 0) {
                cout << cnt << "\n";
                break;
            }
            acc = (acc * 10) + 1;
            acc %= num;
            cnt++;
        }
    }
    return 0;
}