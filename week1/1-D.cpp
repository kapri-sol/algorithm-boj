#include <iostream>
#include <string>

using namespace std;

string text;

bool checkPalindrome(int start, int end) {
    if (start > end) return true;
    if (text[start] != text[end]) return false;
    return checkPalindrome(start + 1, end - 1);
}

int main() {
    cin >> text;
    bool isPalindrome = checkPalindrome(0, text.length() - 1);

    cout << isPalindrome;

    return 0;
}