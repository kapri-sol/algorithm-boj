#include <iostream>
#include <string>

using namespace std;

int alphabet[26];
string ret;
string odd;

int main() {
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++) alphabet[s[i] - 'A']++;

    for(int i = 25; i >= 0; i--) {
        if(alphabet[i] % 2 != 0) odd += 'A' + i;
        if(odd.length() > 1) {
            ret = "I'm Sorry Hansoo";
            break;
        }
        ret = string(alphabet[i] / 2, 'A' + i) + ret;
        ret += string(alphabet[i] / 2, 'A' + i);
    }
    if(odd.length() == 1)
        ret = ret.substr(0, ret.length()/2) + odd[0] + ret.substr(ret.length()/2);
    cout << ret;
    return 0;
}