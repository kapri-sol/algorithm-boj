#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int N, mx = -987654321;
vector<int> num;
vector<char> op;

int calculate(long long a, char op, long long b) {
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else if(op == '*') return a * b;
}

void dfs(int i, int sum) {
    if(i == num.size() - 1) {
        mx =  max(mx, sum);
        return;
    }
    dfs(i +1, calculate(sum, op[i], num[i+1]));
    if(i+2 < num.size()) {
        int tmp = calculate(num[i+1], op[i+1], num[i+2]);
        dfs(i+2, calculate(sum, op[i], tmp));
    }
}

int main() {
    string s;
    cin >> N >> s;

    for(int i = 0; i < N; i++) {
        if('0' <= s[i] && s[i] <= '9') num.push_back(s[i] - '0');
        else op.push_back(s[i]);
    }

    dfs(0, num[0]);
    cout << mx;
    return 0;
}