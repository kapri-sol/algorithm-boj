#include <iostream>
#include <string>
using namespace std;

int N;
int map[64][64];
int cnt;

string dfs(int x, int y, int n) {
    if(n == 1) return to_string(map[x][y]);
    int nn = n / 2;

    string a = dfs(x, y, nn);
    string b = dfs(x, y + nn, nn);
    string c = dfs(x + nn, y, nn);
    string d = dfs(x + nn, y + nn, nn);

    if(a == "0" && b == "0" && c == "0" && d == "0") return "0";
    else if(a == "1" && b == "1" && c == "1" && d == "1") return "1";
    else return "(" + a + b + c + d + ")";
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < N; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    cout << dfs(0, 0, N);
    return 0;
}