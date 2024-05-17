#include <iostream>
#include <vector>
using namespace std;

int minimumLength(string s) {
    int low = 0;
    int high = s.size() - 1;

    while (low < high && s[low] == s[high]) {
        if (s[low] == s[high]) {
            char hold = s[low];

            while (low < high && s[low] == hold && s[high] == hold) {
                low++;
                high--;
            }

            while (low < high && s[low] == hold) {
                low++;
            }

            while (low < high && s[high] == hold) {
                high--;
            }
        }
    }

    return high - low + 1;
}

int main() {
    return 0;
}