#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;
string str[100];
int sum;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> str[i];
    for(int i = 0; i < N; i++) {
        stack<char> st;
        st.push(str[i][0]);
        for(int j = 1; j < str[i].length(); j++) {
            if(!st.empty() && (st.top() == str[i][j])) {
                st.pop();
                continue;
            }
            st.push(str[i][j]);
        }
        if(st.empty()) sum++;
    }
    cout << sum;
    return 0;
}