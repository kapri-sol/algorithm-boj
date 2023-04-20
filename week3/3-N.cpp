#include <iostream>
#include <cmath>

using namespace std;

int K, nums[1024];
vector<int> tree[10];

void search(int start, int end, int level) {
    int mid = (start + end) / 2;
    mid += (start + end) % 2;

    tree[level].push_back(nums[mid]);

    if(mid == start || mid == end) return;

    search(start, mid-1, level + 1);
    search(mid, end, level + 1);
}

void print() {
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < tree[i].size(); j++) {
            cout << tree[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> K;

    for(int i = 0; i < pow(2, K) - 1; i++)
        cin >> nums[i];

    search(0, pow(2, K)-2, 0);
    print();
    return 0;
}