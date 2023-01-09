# include <iostream>
#include <string>

using namespace std;

char str[100];
char alphabet[26];
char bigAlphabet[26];

int main() {
    string input;

    getline(cin, input);

    for(int i = 0; i <= input.length(); i++) {
        char c = input[i];
        if(c >= 'a' && c <= 'z') {
            if(c + 13 <= 'z') {
                input[i] = c + 13;
            } else {
                input[i] = ('a' - 1)  + (13 -('z' - c ));
            }
        } else if(c >= 'A' && c <= 'Z') {
            if(c + 13 <= 'Z') {
                input[i] = c + 13;
            } else {
                input[i] = ('A' - 1)  + (13 -('Z' - c ));
            }
        }
    }
    cout << input;
    return 0;
}