#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int K;
char t[10];
vector<int> nums;
long mx, mn = 9876543210;
string mx_s, mn_s;

void comp(int i) {
    if(i == -1) {
        for(int j = 0; j < 10; j++) {
            nums.push_back(j);
            comp(i + 1);
            nums.pop_back();
        }
    }
    if(i == K) {
        string s;

        for(int j = 0; j <= K; j++) s += '0' + nums[j];
        long result = stol(s);

        if(mx < result) {
            mx = result;
            mx_s = s;
        }
        if(mn > result) {
            mn = result;
            mn_s = s;
        }
        return;
    }

    for(int j = 0; j < 10; j++) {
        vector<int>::iterator it = find(nums.begin(), nums.end(), j);
        if(it != nums.end()) continue;
        if((nums[i] < j && t[i] == '<') || (nums[i] > j && t[i] == '>') ) {
            nums.push_back(j);
            comp(i + 1);
            nums.pop_back();
        }
    }
}

int main() {
    cin >> K;
    for(int i = 0; i < K; i++) cin >> t[i];

    comp(-1);

    cout << mx_s << "\n" << mn_s;
    return 0;
}