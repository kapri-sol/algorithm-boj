#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
string question[100000];
string poketmon[100000];
map<string, int>pokeNumMap;

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> poketmon[i];
        pokeNumMap[poketmon[i]] = i + 1;
    };

    for(int i = 0; i < M; i++) cin >> question[i];
    for(int i = 0; i < M; i++) {
        if(isdigit(question[i][0])) cout << poketmon[stoi(question[i]) - 1] << "\n";
        else cout << pokeNumMap.find(question[i])->second << "\n";
    }
    return 0;
}