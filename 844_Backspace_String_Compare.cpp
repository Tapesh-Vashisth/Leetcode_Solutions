#include <iostream>
#include <vector>
using namespace std;


bool backspaceCompare(string s, string t) {
    int first = s.size() - 1;
    int second = t.size() - 1;

    while (true) {
        int back = 0;
        int erased = 0;

        if (first >= 0 && s[first] == '#') {
            back++;
            first--;
        }

        while (first >= 0 && back > erased) {
            if (s[first] == '#') {
                back++;
            } else {
                erased++;
            }

            first--;
        }

        back = 0;
        erased = 0;

        if (second >= 0 && t[second] == '#') {
            back++;
            second--;
        }

        while (second >= 0 && back > erased) {
            if (t[second] == '#') {
                back++;
            } else {
                erased++;
            }

            second--;
        }

        if (first < 0 && second < 0) {
            break;
        } else if (first >= 0 && second < 0) {
            if (s[first] == '#') {
                continue;
            } else {
                return false;
            }
        } else if (second >= 0 && first < 0) {
            if (t[second] == '#') {
                continue;
            } else {
                return false;
            }
        } else {
            if (s[first] == '#' || t[second] == '#') {
                continue;
            }
        }

        if (s[first] != t[second]) {
            return false;
        }

        first--;
        second--;
    }       

    return true;
}

int main() {
    return 0;
}