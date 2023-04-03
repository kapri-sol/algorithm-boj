#include <iostream>
#include <vector>

using namespace std;

int T;
unsigned long long N;

int main() {
    cin >> T;
    vector<unsigned long long > v;

    for(int t = 0; t < T; t++) {
        cin >> N;
        int acc2 = 0;
        int acc5 = 0;

        for(int i = 2; i <= N; i*=2) {
            acc2 += N / i;
        }

        for(int i = 5; i <= N; i*=5) {
            acc5 += N / i;
        }

        v.push_back(min(acc2, acc5));
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    return 0;
}