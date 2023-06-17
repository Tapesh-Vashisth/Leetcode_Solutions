#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector <unordered_map <long long, long long>> dp; 

long long helper(vector <int> & arr1, vector <int> & arr2, int index, int prev) {
    if (index == arr1.size()) {
        return 0;
    }
    
    if (dp[index][prev] != 0) {
        return dp[index][prev];
    }

    // do not replace
    long long first = INT32_MAX;

    if (arr1[index] > prev) {
        first = helper(arr1, arr2, index + 1, arr1[index]);
    }

    // replace 
    int pos = lower_bound(arr2.begin(), arr2.end(), prev + 1) - arr2.begin();

    long long second = INT32_MAX;
    if (pos != arr2.size()) {
        second = helper(arr1, arr2, index + 1, arr2[pos]) + 1;
    }

    dp[index][prev] = min(first, second);

    return dp[index][prev];
}

int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    dp = vector <unordered_map <long long, long long>> (arr1.size());

    sort(arr2.begin(), arr2.end());

    long long ans = helper(arr1, arr2, 0, INT32_MIN);

    return ans == INT32_MAX ? -1: ans;
}

int main() {
    return 0;
}