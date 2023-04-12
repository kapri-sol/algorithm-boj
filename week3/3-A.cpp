#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, M;
int map[50][50];
vector<pair<int, int> > chicken;
vector<pair<int, int> > home;

int countDist(pair<int, int> a, pair<int, int> b) {
    int x = max(a.first, b.first) - min(a.first, b.first);
    int y = max(a.second, b.second) - min(a.second, b.second);
    return x + y;
}

template <typename T>
vector<vector<T> > comb(vector<T> v, int c) {
    vector<int> num(v.size());
    vector<vector<T> > ret;

    for(int i = 0; i < c; i++) num[i] = 1;

    do {
        vector<T> t;

        for(int i = 0; i < num.size(); i++) {
            if(num[i] == 1) t.push_back(v[i]);
        }
        ret.push_back(t);
    } while (next_permutation(num.begin(), num.end()));

    return ret;
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) home.push_back(make_pair(i, j));
            if(map[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }

    vector<vector<pair<int, int> > > v = comb(chicken, M);

    for(int i = 0; i < v.size(); i++) {

    }
    return 0;
}