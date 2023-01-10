#include <iostream>
#include <map>
#include <string>

using namespace std;

int TC;
int ret[100];
int main() {
    cin >> TC;
    for(int i = 0; i < TC; i++) {
        int N;
        cin >> N;
        map<string, int> clothMap;
        for (int j = 0; j < N; j++) {
            string wear, depart;
            cin >> wear >> depart;
            clothMap[depart]++;
        }
        ret[i] = 1;
        for(auto depart : clothMap) {
            ret[i] *= (depart.second + 1);
        }
        ret[i]--;
    }

    for(int i = 0; i < TC; i++) cout << ret[i] << "\n";
    return 0;
}
