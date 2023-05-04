#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, a_t, b_t, c_t, d_t, INF = 987654321, mn = INF;

struct Food {
    int a;
    int b;
    int c;
    int d;
    int price;
};
Food list[15], sum;
map<int, vector<vector<int> > > ret;

int main() {
    cin >> N >> a_t >> b_t >> c_t >> d_t;

    for(int i = 0; i < N; i++)
        cin >> list[i].a >> list[i].b >> list[i].c >> list[i].d >> list[i].price;

    for(int i = 1; i < (1 << N); i++) {
        sum.a = sum.b = sum.c = sum.d = sum.price = 0;
        vector<int> v;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                v.push_back(j + 1);
                sum.a += list[j].a;
                sum.b += list[j].b;
                sum.c += list[j].c;
                sum.d += list[j].d;
                sum.price += list[j].price;
            }
        }

        if(sum.a >= a_t && sum.b >= b_t && sum.c >= c_t && sum.d >= d_t ) {
            if(sum.price <= mn) {
                mn = sum.price;
                ret[mn].push_back(v);
            }
        }
    }
    if(mn == INF) cout << -1;
    else {
        sort(ret[mn].begin(), ret[mn].end());
        cout << mn << "\n";
        for(int i = 0; i < ret[mn][0].size(); i++) {
            cout << ret[mn][0][i] << " ";
        }
    }
    return 0;
}