#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string check(string s) {
    stack<char> st;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        } else if(s[i] == ')') {
            if(!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                return "no";
            }
        } else if(s[i] == ']') {
            if(!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                return "no";
            }
        }
    }

    if(!st.empty()) return "no";

    return "yes";
}

int main () {
    vector<string> v;
    while(true) {
        string s;
        getline(cin, s);
        if(s == ".") break;
        v.push_back(s);
    }

    for(int i = 0; i < v.size(); i++ ){
        cout << check(v[i]) << "\n";
    }

    return 0;
}