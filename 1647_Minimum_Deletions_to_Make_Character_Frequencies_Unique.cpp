#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int minDeletions(string s) {
    vector <int> hash(26, 0);

    for (auto it: s) {
        hash[it - 'a']++;
    }

    vector <int> anotherHash(s.size() + 1, 0);

    int mx = 0;
    for (auto it: hash) {
        anotherHash[it]++;
        mx = max(mx, it);
    }

    int ans = 0;
    int temp = 0;

    while (mx) {
        if (temp + anotherHash[mx] > 1) {
            ans += anotherHash[mx] - 1;
            temp += (temp + anotherHash[mx] - 1);
        }

        mx--;
    }

    return ans;
}

int main() {
    return 0;
}