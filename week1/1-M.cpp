#include <iostream>
#include <string>

using namespace std;

int N;
string str[100];
int sum;
// ABAB
// AABB
// ABBA

int solve(string s) {
    int start = 0;
    int end = s.find_last_of(s[start]);
//    cout << start << " " << end << "\n";
    if(end == string::npos || end == 0) return 0;
    if(end - start == 1 && s[start] == s[end]) return 1;
//    cout << s.substr(1, end) << " " << solve(s.substr(end, s.length() - 1));
//    cout <<s.substr(start + 1, end - 1) << "\n";
    if(s.length() - end > 0) solve(s.substr(start + 1, end - 1)) & solve(s.substr(end, s.length()));
    return solve(s.substr(start + 1, end - 1));
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> str[i];
    for(int i = 0; i < N; i++) {
//        solve(str[i]);
//        cout << "\n";
        sum += solve(str[i]);
    }
    cout << sum;
    return 0;
}