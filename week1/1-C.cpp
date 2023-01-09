#include <iostream>

using namespace std;

int cash[3];
int car[3][2];
int sum = 0;

int main() {
    for (int i = 0; i < 3; i++) cin >> cash[i];
    for (int i = 0; i < 3; i++) cin >> car[i][0] >> car[i][1];

    for(int i = 1; i < 101; i++) {
        int fee = cash[0];
        int count = 0;
        for(int j = 0; j < 3; j++) {
            if( i >= car[j][0] && i < car[j][1] ) {
                count++;
            }
        }
        if(count == 2) fee = cash[1];
        if(count == 3) fee = cash[2];
        sum += count * fee;
    }
    cout << sum;
    return 0;
}
