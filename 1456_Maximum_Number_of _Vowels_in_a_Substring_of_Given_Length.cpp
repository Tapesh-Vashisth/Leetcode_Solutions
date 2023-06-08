#include <iostream>
#include <vector>
using namespace std;

int maxVowels(string s, int k) {
    int ans = 0;
    int low = 1;
    int high = k;
    int counter = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            counter++;
        }
    }

    ans = counter;

    while (high < s.size()) {
        if (s[low] == 'a' || s[low] == 'e' || s[low] == 'low' || s[low] == 'o' || s[low] == 'u') {
            counter--;
        }

        if (s[high] == 'a' || s[high] == 'e' || s[high] == 'high' || s[high] == 'o' || s[high] == 'u') {
            counter++;
        }

        ans = max(ans, counter);

        low++;
        high++;
    }

    return ans;
}

int main() {
    return 0;
}