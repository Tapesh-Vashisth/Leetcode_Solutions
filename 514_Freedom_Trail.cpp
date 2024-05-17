#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> dp;

int helper(int index, int ringIndex, string & ring, string & key) {
    int ret = 1;

    if (index >= key.size() - 1) {
        return ret;
    }

    if (dp[index][ringIndex] != -1) {
        return dp[index][ringIndex];
    }

    int left = 0;
    // left 
    while (ring[(ringIndex - left + ring.size()) % ring.size()] != key[index + 1]) {
        left++;
    }

    left += helper(index + 1, (ringIndex - left + ring.size()) % ring.size(), ring, key);

    int right = 0;
    // right 
    while (ring[(ringIndex + right) % ring.size()] != key[index + 1]) {
        right++;
    }

    right += helper(index + 1, (ringIndex + right) % ring.size(), ring, key);

    return dp[index][ringIndex] = ret + min(left, right);
}

int findRotateSteps(string & ring, string & key) {
    int sub = 0;
    if (ring[0] != key[0]) {
        key.insert(key.begin(), ring[0]);
        sub = 1;
    }

    dp = vector <vector <int>> (key.size(), vector <int> (ring.size(), -1));

    return helper(0, 0, ring, key) - sub;
}

int main() {
    return 0;
}