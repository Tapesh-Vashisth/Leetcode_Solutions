#include <iostream>
#include <vector>
using namespace std;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

long long getithbit(long long x, long long i){
    long long bit = (long long)1 << (i - 1);
    return (x & bit ? 1 : 0);
}

long long clearithbit(long long x, long long i){
    long long bit = ~((long long)1 << (i - 1));
    return (x & bit);
}

long long setithbit(long long x, long long i){
    return (x | ((long long)1 << (i - 1)));
}

vector <vector <int>> dp;

int helper(vector <int> & nums, int move, int hash) {
    if (move >= nums.size() / 2) {
        return 0;
    }

    if (dp[move][hash] != -1) {
        return dp[move][hash];
    }

    int hold = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (!getithbit(hash, i + 1)) {
            for (int j = i; j < nums.size(); j++) {
                if (!getithbit(hash, j + 1)) {
                    setithbit(hash, i + 1);
                    setithbit(hash, j + 1);
                    int temp = ((move + 1) * gcd(nums[i], nums[j])) + helper(nums, move + 1, hash);
                    hold = max(hold, temp);
                }
            }
        }
    }

    dp[move][hash] = hold;

    return hold;
}

int maxScore(vector<int>& nums) {
    dp = vector <vector <int>> (nums.size()/2, vector <int> (1 << nums.size(), -1));
    int ans = helper(nums, 0, 0);
}

int main() {
    return 0;
}