#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string > v;

string deleteZero(string s) {
    if(s.length() >= 2 && s[0] == '0') return deleteZero(s.substr(1, s.length() - 1));
    else return s;
}

int findNum(string s, int i) {
    while(i < s.length()) {
        if(s[i] < '0' || s[i] > '9') return i;
        i++;
    }
}

void split(string s) {
    int start = 0;
    while(start < s.length()) {
        int end = findNum(s, start);
        if(start == end) start++;
        else {
            string numStr = s.substr(start, end - start);
            numStr = deleteZero(numStr);
            v.push_back(numStr);
            start += end - start;
        }
    }
}

bool cmp(string a, string b) {
    if(a.length() == b.length()) {
        for(int i = 0; i < a.length(); i++) {
            if(a[i] == b[i]) continue;
            else return a[i] < b[i];
        }
        return false;
    }
    return a.length() < b.length();
}

string in[100];
int T;
int main() {
    cin >> T;
    for(int i = 0; i < T; i++)
        cin >> in[i];
    for(int i = 0; i < T; i++)
        split(in[i]);

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    return 0;
}