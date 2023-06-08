#include <iostream>
using namespace std;

bool isMatch(string s, string p) {
    bool turn = false;
    int turnwherep = -1;
    int turnwheres = -1;
    int first = 0;
    int second = 0;
    while (first < s.size() && second < p.size()) {
        if (turn == false) {
            if (p[second] != '*') {
                if (p[second] != '?') {
                    if (s[first] == p[second]) {
                        first++;
                        second++;
                    } else {
                        return false;
                    }
                } else {
                    first++;
                    second++;
                }
            } else {
                if (second + 1 >= p.size()) {
                    return true;
                } else {
                    turn = true;
                    turnwherep = second; 
                    second++;
                }
            }
        } else {
            if (s[first] == p[second]) {
                turnwheres = first + 1;
                first++;
                second++;
            } else {
                first++;
            }
        }
    }
}

int main() {
    return 0;
}