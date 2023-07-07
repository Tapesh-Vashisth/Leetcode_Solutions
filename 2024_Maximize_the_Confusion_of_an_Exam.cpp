#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {
    // true 
    int mx = 0;
    int current = 0;
    int currentk = 0;
    int low = 0;
    int high = 0;

    while (high < answerKey.size()) {
        if (currentk <= k) {
            if (answerKey[high] == 'T') {
                ;
            } else {
                currentk++;
            }

            current++;
            high++;
        } else {
            if (answerKey[low] == 'T') {
                ;
            } else {
                currentk--;
            }

            current--;

            low++;
        }

        if (currentk <= k) {
            mx = max(mx, current); 
        }
    }

    // false
    low = 0;
    high = 0;
    currentk = 0;
    current = 0;
    while (high < answerKey.size()) {
        if (currentk <= k) {
            if (answerKey[high] == 'F') {
                ;
            } else {
                currentk++;
            }

            current++;
            high++;
        } else {
            if (answerKey[low] == 'F') {
                ;
            } else {
                currentk--;
            }

            current--;

            low++;
        }

        if (currentk <= k) {
            mx = max(mx, current); 
        }
    }

    return mx;
}

int main() {
    return 0;
}