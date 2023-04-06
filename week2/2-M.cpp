#include <iostream>
#include <string>

using namespace std;

int num[10000];
int N;

int main() {
    cin >> N;

    int n = 666;
    int i = 0;

    while(num[N-1] == 0) {
        if(to_string(n).find("666") != string::npos) {
            num[i] = n;
            i++;
        }
        n++;
    }

    cout << num[N-1];
    return 0;
}