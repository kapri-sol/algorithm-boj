#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int N, C;
int in[1000];
map<int, int> msg;
map<int, int> order;
vector<int> v;

bool compare(int a, int b) {
    if(msg[a] == msg[b]) {
        return order[a] < order[b];
    }
    return msg[a] > msg[b];
}

int main() {
    cin >> N >> C;

    for(int i = 0; i < N; i++) {
        cin >> in[i];
        v.push_back(in[i]);
        if(!msg[in[i]]) {
            msg[in[i]] = 0;
        }
        msg[in[i]]++;

        if(!order[in[i]]) {
            order[in[i]] = i + 1;
        }
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

    return 0;
}