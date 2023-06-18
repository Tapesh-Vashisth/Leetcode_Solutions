#include <iostream>
#include <vector>
#include <map>
using namespace std;

const long long mod = 1e9 + 7;


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

long long updateithbit(long long x, long long i, long long v){
    long long bit = clearithbit(x, i);
    return (bit | (v << (i - 1)));
}

vector <vector <long long>> dp;

long long helper(vector <int> & nums, int index, vector <bool> & visited, vector <vector <int>> & graph, int counter, int val) {
    if (visited[index]) {
        if (counter == nums.size() - 1) {
            return 1;
        }

        if (dp[index][val] != -1) {
            return dp[index][val];
        }

        visited[index] = false;

        long long hold = 0;
        for (int i = 0; i < graph[index].size(); i++) {
            if (visited[graph[index][i]]) {
                int newVal = setithbit(val, index + 1);
                hold = ((hold % mod) + (helper(nums, graph[index][i], visited, graph, counter + 1, newVal) % mod)) % mod;
            }
        }

        visited[index] = true;

        dp[index][val] = hold;

        return hold;
    } else {
        return 0;
    }
}

int specialPerm(vector<int>& nums) {
    vector <vector <int>> graph(nums.size());

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if ((nums[i] % nums[j] == 0) || (nums[j] % nums[i] == 0)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    long long ans = 0;

    dp = vector <vector <long long>> (14, vector <long long> (1 << (nums.size() + 1), -1));

    for (int i = 0; i < nums.size(); i++) {
        vector <bool> visited (nums.size(), true);
        int val = setithbit(0, i + 1);
        ans = ((ans % mod) + (helper(nums, i, visited, graph, 0, val) % mod)) % mod;
    }

    return ans;
}

int main() {
    return 0;
}