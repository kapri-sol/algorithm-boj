#include <iostream>
#include <string>

using namespace std;

int inputCnt ;
string player[150];
string ret = "PREDAJA";
int alphabet[26];

int main () {
    cin >> inputCnt;
    for(int i = 0; i < inputCnt; i++) cin >> player[i];

    for (int i = 0; i < inputCnt; i++) {
        if(!alphabet[player[i][0] - 'a']) {
            alphabet[player[i][0] - 'a'] = 0;
        }
        alphabet[player[i][0] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] >= 5) {
            if(ret == "PREDAJA") {
                ret = "";
            }
            ret += i + 'a';
        }
    }

    cout << ret;
    return 0;
}