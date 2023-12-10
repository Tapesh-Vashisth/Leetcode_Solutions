#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long sum(vector <long long> & prefixSum, int left, int right) {
    long long r = prefixSum[right + 1];
    long long l = prefixSum[left];

    return r - l;
}

const long long mod = 1e9 + 7;

int maxSumMinProduct(vector<int>& nums) {
    vector <int> leftMin(nums.size(), -1);
    vector <int> rightMin(nums.size(), nums.size());

    stack <int> store;

    for (int i = 0; i < nums.size(); i++) {
        while (!store.empty() && nums[store.top()] >= nums[i]) {
            store.pop();
        }

        if (store.empty()) {
            leftMin[i] = -1;
        } else {
            leftMin[i] = store.top();
        }

        store.push(i);
    }

    while (!store.empty()) {
        store.pop();
    }

    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!store.empty() && nums[store.top()] >= nums[i]) {
            store.pop();
        }

        if (store.empty()) {
            rightMin[i] = nums.size();
        } else {
            rightMin[i] = store.top();
        }

        store.push(i);
    }    

    
    vector <long long> prefixSum = {0};

    for (int i = 0; i < nums.size(); i++) {
        prefixSum.push_back(nums[i] + prefixSum[prefixSum.size() - 1]);
    }

    long long ans = INT32_MIN;

    for (int i = 0; i < nums.size(); i++) {
        int left = leftMin[i] + 1;
        int right = rightMin[i] - 1;

        ans = max((long long)ans, nums[i] * sum(prefixSum, left, right));
    }

    return ans % mod;
}   


int main() {
    return 0;
}