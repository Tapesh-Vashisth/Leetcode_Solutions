#include <iostream>
#include <vector>
using namespace std;

int characterReplacement(string s, int k) {
    int limit = 0;
    for (auto it: s) {
        limit = max(limit, it - 'A');
    }

    int mx = 0;
    for (int i = 0; i <= limit; i++) {
        char compare = 'A' + i;
        int current = 0;
        int currentk = 0;
        int low = 0;
        int high = 0;
        while (high < s.size()) {
            if (currentk <= k) {
                if (s[high] == compare) {
                    ;
                } else {
                    currentk++;
                }

                current++;
                high++;
            } else {
                if (s[low] == compare) {
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
    }

    return mx;
}


int main() {
    return 0;
}