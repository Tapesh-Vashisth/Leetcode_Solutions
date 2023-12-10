#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    vector <int> leftMax(nums.size(), -1);
    vector <int> rightMax(nums.size(), nums.size());
    vector <int> leftMin(nums.size(), -1);
    vector <int> rightMin(nums.size(), nums.size());

    stack <int> store;

    // leftMin 
    for (int i = 0; i < nums.size(); i++) {
        if (store.empty()) {
            ;
        } else {
            while (!store.empty() && nums[store.top()] >= nums[i]) {
                store.pop();
            }

            if (!store.empty()) {
                leftMin[i] = store.top();
            }

        }

        store.push(i);
    }

    while (!store.empty()) {
        store.pop();
    }

    // leftMax 
    for (int i = 0; i < nums.size(); i++) {
        if (store.empty()) {
            ;
        } else {
            while (!store.empty() && nums[store.top()] <= nums[i]) {
                store.pop();
            }

            if (!store.empty()) {
                leftMax[i] = store.top();
            }

        }

        store.push(i);
    }

    while (!store.empty()) {
        store.pop();
    }

    // rightMin
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (store.empty()) {
            ;
        } else {
            while (!store.empty() && nums[store.top()] > nums[i]) {
                store.pop();
            }

            if (!store.empty()) {
                rightMin[i] = store.top();
            }

        }

        store.push(i);
    } 

    while (!store.empty()) {
        store.pop();
    }

    // rightMax
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (store.empty()) {
            ;
        } else {
            while (!store.empty() && nums[store.top()] < nums[i]) {
                store.pop();
            }

            if (!store.empty()) {
                rightMax[i] = store.top();
            }

        }

        store.push(i);
    } 


    long long maxSum = 0;
    long long minSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        // max 
        maxSum += (long long)nums[i] * (i - leftMax[i]) * (rightMax[i] - i);

        // min 
        minSum += (long long)nums[i] * (i - leftMin[i]) * (rightMin[i] - i);
    }

    return maxSum - minSum;
}

int main() {
    return 0;
}