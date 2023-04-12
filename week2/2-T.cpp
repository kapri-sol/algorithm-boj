#include <iostream>
#include <stack>

using namespace std;

int N;
int A[1000000];
int ret[1000000];

int main() {
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> A[i];

    stack<int> st;
    int idx = 0;

    while(idx < N) {

        if(st.empty()) {
            st.push(idx);
            continue;
        }

        int top = st.top();

        if(A[top] < A[idx]) {
            ret[top] = A[idx];
            st.pop();
        } else {
            st.push(idx);
            idx++;
        }
    }

    while(!st.empty()) {
        ret[st.top()] = -1;
        st.pop();
    }

    for(int i = 0; i < N; i++) cout << ret[i] << " ";

    return 0;
}