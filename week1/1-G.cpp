#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, pos;
    string pattern, pPattern, sPattern, s[100];

    cin >> N >> pattern;
    pos = pattern.find('*');
    pPattern = pattern.substr(0, pos);
    sPattern = pattern.substr(pos+1);

    for (int i = 0; i < N; i++) cin >> s[i];

    for (int i = 0 ; i < N; i++) {
        if(pPattern.length() + sPattern.length() > s[i].length()) {
            cout << "NE\n";
        } else {
            string pS = s[i].substr(0, pPattern.length());
            string sS = s[i].substr(s[i].length() - sPattern.length());
            pS == pPattern && sS == sPattern?
                cout <<  "DA\n" : cout << "NE\n";
        }
    }
    return 0;
}
