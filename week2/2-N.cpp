#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int T;
vector<string> results;

string check(string s) {
    stack<char> st;

    for(int i = 0; i < s.length(); i++) {
        if(st.empty() || s[i] == '(') {
            st.push(s[i]);
        } else {
            if(st.top() == '(' && !st.empty()) {
                st.pop();
            } else {
                return "NO";
            }
        }
    }

    if(!st.empty()) return "NO";

    return "YES";
}

int main() {
    cin >> T;

    for(int i = 0; i < T; i++) {
        string s;
        cin >> s;
        results.push_back(check(s));
    }

    for(int i = 0; i < T; i++) {
        cout << results[i] << "\n";
    }
    return 0;
}