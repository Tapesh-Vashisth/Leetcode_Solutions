#include <iostream>
#include <map>
using namespace std;

int longestPalindrome(string s) {
    map <char, int> store;

    for (int i = 0; i < s.size(); i++) {
        store[s[i]]++;
    }   

    bool decider = false;
    int ans = 0;

    for (auto it: store) {
        if (it.second % 2) {
            decider = true;
        }

        ans += (it.second/2) * 2;
    }

    ans += decider;

    return ans;
}

int main() {
    return 0;
}