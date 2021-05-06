#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string make_palindrome(string s) {
    int head = 0, tail = s.size() - 1;
    string patch;
    bool is_palindrome = false;
    for (head = 0; head < tail && !is_palindrome; head++) {
        int size = (tail - head + 1) / 2, i;
        for (i = 0; i < size; i++) {
            if (s[head + i] != s[tail - i]) break;
        }
        if (i == size) {
            is_palindrome = true;
            head--;
        }
    }
    patch = s.substr(0, head);
    reverse(patch.begin(), patch.end());
    return s + patch;
}

int main() {
    string s;
    while (getline(cin, s)) cout << make_palindrome(s) << endl;
    return 0;
}
