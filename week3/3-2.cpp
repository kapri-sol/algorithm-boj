#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int num[10];
int points[32];
int mx;
vector<int> map[32];
stack<int> st;

void setMap() {
    for(int i = 1; i <= 20; i++) {
        points[i] = 2 * i;
        map[i].push_back(i+1);
    }

    map[5].push_back(21);
    points[21] = 13;
    map[21].push_back(22);
    points[22] = 16;
    map[22].push_back(23);
    points[23] = 19;
    map[23].push_back(24);
    points[24] = 25;

    map[10].push_back(25);
    points[25] = 22;
    map[25].push_back(26);
    points[26] = 24;
    map[26].push_back(24);

    map[15].push_back(27);
    points[27] = 28;
    map[27].push_back(28);
    points[28] = 27;
    map[28].push_back(29);
    points[29] = 26;
    map[29].push_back(24);

    map[24].push_back(30);
    points[30] = 30;
    map[30].push_back(31);
    points[31] = 35;
    map[31].push_back(20);
}

int checkPoint(int current, int count) {
    int point = 0;
    for(int i = 0; i < count; i++) {
        if(current + count == 31) return point;
        point += points[current + i];
    }
    return point;
}

int dfs(int current) {
    if(current == 32) return 0;

    for(int i = 0; i < 4; i++) {

    }
}

int main() {
    for(int i = 0; i < 10; i++)
        cin >> num[i];

    return 0;
}