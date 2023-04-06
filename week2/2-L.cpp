#include <iostream>
#include <string>

using namespace std;

int N;
int totalScore[2] = {0, 0};
int timeSum[2] = {0, 0};
int scores[100];
int scoreTimes[100];

int toInt(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

string toString(int n) {
    string m = "00" + to_string(n / 60);
    string s = "00" + to_string(n % 60);

    return m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2);
}

int main() {
    cin >> N;


    for(int i = 0; i < N; i++) {
        int n;
        string  s;
        cin >> n >> s;
        scores[i] = n -1;
        scoreTimes[i] = toInt(s);
    }

    scoreTimes[N] = 48 * 60;

    for(int i = 1; i < N + 1; i++) {
        totalScore[scores[i-1]]++;

        if(totalScore[0] > totalScore[1]) {
            timeSum[0] += scoreTimes[i] - scoreTimes[i-1];
        } else if(totalScore[0] < totalScore[1]) {
            timeSum[1] += scoreTimes[i] - scoreTimes[i-1];
        }
    }

    cout << toString(timeSum[0]) << "\n" << toString(timeSum[1]);
    return 0;
}