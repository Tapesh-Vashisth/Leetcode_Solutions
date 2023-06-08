#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

vector <vector <long long>> dp;


long long helper(vector <vector <int>> & store, string & target, int storeIndex, int targetIndex) {
    if (storeIndex >= store.size()) {
        if (targetIndex < target.size()) {
            return 0;
        } else {
            return 1;
        }
    } else {
        if (targetIndex >= target.size()) {
            return 1;
        }
    }

    if (dp[storeIndex][targetIndex] != -1) {
        return dp[storeIndex][targetIndex];
    }

    long long take = 0;

    // take 
    if (store[storeIndex][target[targetIndex] - 'a'] > 0) {
        take = ((store[storeIndex][target[targetIndex] - 'a'] % mod) * (helper(store, target, storeIndex + 1, targetIndex + 1) % mod));
    }

    // not take 
    long long notTake = helper(store, target, storeIndex + 1, targetIndex);


    dp[storeIndex][targetIndex] = (take + notTake) % mod;

    return (take + notTake) % mod;
}

int numWays(vector<string>& words, string target) {
    vector <vector <int>> store(words[0].size(), vector <int> (26, 0));

    dp = vector <vector <long long>> (1001, vector <long long> (1001, -1));

    for (int j = 0; j < words.size(); j++) {
        for (int i = 0; i < words[j].size(); i++) {
            store[i][words[j][i] - 'a']++;
        }
    }

    long long ans = helper(store, target, 0, 0);

    return ans;
}

int main() {
    return 0;
}