#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const long long mod = 1e9 + 7;

long long rev(int hold) {
    string temp = to_string(hold);
    reverse(temp.begin(), temp.end());

    return stoi(temp);
}

int countNicePairs(vector<int>& nums) {
    map <int, long long> store;

    int ans = 0;
    for (auto it: nums) {
        long long temp = it - rev(it);

        ans = ((ans % mod) + (store[temp] % mod)) % mod;

        store[temp]++;
    }

    return ans;
}

int main() {
    return 0;
}