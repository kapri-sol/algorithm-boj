#include <iostream>
#include <string>

using namespace std;

int N, K, ret;
int alphabet[26];
string words[50];

int check() {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int j;
        for(j = 4; j < words[i].length() - 4; j++) {
            if(!alphabet[words[i][j] - 'a']) break;
        }
        if(j == words[i].length() - 4) cnt++;
    }
    return cnt;
}

void comb(int here, int cnt) {
    if(here > 26) return;
    if(cnt == K - 5) {
        ret = max(ret, check());
        return;
    }
    comb(here + 1, cnt);

    if(here == 0 || here == 'n' - 'a' || here == 't' - 'a' || here == 'i' - 'a' || here == 'c' - 'a') return;

    alphabet[here] = 1;
    comb(here + 1, cnt + 1);
    alphabet[here] = 0;
}

int main() {
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> words[i];
    }

    if(K < 5) cout << 0;
    else {
        alphabet[0] = alphabet['n' - 'a'] = alphabet['t' - 'a'] = alphabet['i' - 'a'] = alphabet['c' - 'a'] = 1;
        comb(0, 0);
        cout << ret;
    }

    return 0;
}