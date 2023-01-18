#include <iostream>

using namespace std;

int H, W;
int map[100][100];
int nmap[100][100];

void check(int x, int y) {
    if(map[x][y]) {
        nmap[x][y] = 0;
        return;
    }

    for(int ny = y-1; ny >= 0; ny--) {
        if(map[x][ny]) {
            nmap[x][y] = y - ny;
            return;
        }

    }
    nmap[x][y] = -1;
}

int main() {
    cin >> H >> W;
    string s;

    for(int i = 0; i < H; i++) {
        cin >> s;
        for(int j = 0; j < W; j++) {
            if(s[j] == '.') continue;
            if(s[j] == 'c') map[i][j] = 1;
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            check(i, j);
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << nmap[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}