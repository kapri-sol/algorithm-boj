#include <iostream>
#include <string>
#include <vector>

using namespace std;

string input;

vector<string> ret;

bool isAEIOU(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isContainAEIOU(string s) {
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) if(isAEIOU(s[i])) cnt++;
    return cnt > 0;
}

bool isRepeat(string s) {
    int aCnt = 0, bCnt = 0;
    char prevC;

    for(int i = 0; i < s.length(); i++) {
        if(!isAEIOU(prevC) && isAEIOU(s[i])) {
            bCnt = 0;
            aCnt++;
        } else if(isAEIOU(prevC) && !isAEIOU(s[i])) {
            aCnt = 0;
            bCnt++;
        } else if(isAEIOU(s[i])) {
            aCnt++;
        } else if(!isAEIOU(s[i])) {
            bCnt++;
        }

        if(s[i] == prevC && s[i] != 'e' && s[i] != 'o') return true;
        if(aCnt >= 3 || bCnt >= 3) return true;

        prevC = s[i];
    }
    return false;
}
int main() {
    while (input != "end") {
        cin >> input;
        if(isContainAEIOU(input) && !isRepeat(input)) ret.push_back("<" + input + "> is acceptable.");
        else ret.push_back("<" + input + "> is not acceptable.");
    }
    for(int i = 0; i < ret.size() - 1; i++) cout << ret[i] << "\n";
    return 0;
}