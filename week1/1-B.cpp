#include <iostream>
#include <string>

using  namespace std;
int alphabet[26];

int main() {
    string input;
    cin >> input;

    for(int i = 0; i < 26; i++) alphabet[i] = 0;
    for(int i = 0; i < input.size(); i++) alphabet[input[i] - 'a'] += 1;


    for(int i = 0; i < 26; i++) cout << alphabet[i] << " ";
    cout << "\n";
    return 0;
}