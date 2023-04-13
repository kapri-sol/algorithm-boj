#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int map[50][50];
vector<pair<int, int> > chicken;
vector<pair<int, int> > home;
int minDist = 999999;

int countDist(pair<int, int> a, pair<int, int> b) {
    int x = max(a.first, b.first) - min(a.first, b.first);
    int y = max(a.second, b.second) - min(a.second, b.second);
    return x + y;
}

void comb(int start, vector<pair<int, int> > v) {
    if(v.size() == M) {
        int totalChickenDist = 0;
        for(int i = 0; i < home.size(); i++) {
            int chickenDist = 999999;
            for(int j = 0; j < v.size(); j++) {
                chickenDist = min(chickenDist, countDist(home[i], v[j]));
            }
            totalChickenDist += chickenDist;
        }
        minDist = min(minDist, totalChickenDist);
        return;
    }

    for(int i = start + 1; i < chicken.size(); i++) {
        v.push_back(chicken[i]);
        comb(i, v);
        v.pop_back();
    }
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

    comb(-1, vector<pair<int, int> >());

    cout << minDist;
    return 0;
}