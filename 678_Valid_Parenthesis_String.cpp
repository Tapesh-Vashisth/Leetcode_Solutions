#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool checkValidString(string & s) {
    // from front 
    queue <int> storeStar;
    int current = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            current++;
        } else if (s[i] == ')') {
            current--;

            if (current < 0) {
                if (!storeStar.empty()) {
                    int hold = storeStar.front();
                    storeStar.pop();

                    s[hold] = '(';
                    current = 0;
                } else {
                    return false;
                }
            }
        } else {
            storeStar.push(i);
        }
    }


    // from back 
    while (!storeStar.empty()) {
        storeStar.pop();
    }


    current = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            current--;

            if (current < 0) {
                if (!storeStar.empty()) {
                    int hold = storeStar.front();
                    storeStar.pop();

                    s[hold] = ')';
                    current = 0;
                } else {
                    return false;
                }
            }
        } else if (s[i] == ')') {
            current++;
        } else {
            storeStar.push(i);
        }
    }

    return true;
}

int main() {
    return 0;
}