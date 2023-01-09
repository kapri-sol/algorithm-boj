#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dwarfs;
int sum = 0;
pair<int, int> ret;

int main() {
    vector<int> v;

    for (int i = 0; i < 9; i++) {
        int input;
        cin >> input;
        dwarfs.push_back(input);
        sum += input;
    }

    sort(dwarfs.begin(), dwarfs.end());

    for(int & dwarf : dwarfs) cout << dwarf << "\n";

    do {

    } while (next_permutation(dwarfs.begin(), dwarfs.end()));

    return 0;
}