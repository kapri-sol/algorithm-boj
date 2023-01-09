#include <iostream>

using namespace std;

int cash[3];
int car[3][2];
int sum = 0;
int main() {
    for (int i = 0; i < 3; i++) cin >> cash[i];
    for (int i = 0; i < 3; i++) cin >> car[i][0] >> car[i][1];

    for (int i = 0; i < 3; i++) {
        sum += (car[i][1] - car[i][0]) * cash[i];
    }

    cout << sum;
    return 0;
}