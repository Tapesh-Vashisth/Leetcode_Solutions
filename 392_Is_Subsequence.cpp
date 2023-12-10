#include <iostream>
using namespace std;

bool isSubsequence(string s, string t) {
    int first = 0;
    int second = 0;

    while (first < s.size() && second < t.size()) {
        if (s[first] == t[second]) {
            first++;
            second++;
        } else {
            second++;
        }
    }

    return first == s.size();
}

int main() {
    return 0;
}