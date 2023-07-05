#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int hold = 0;
    stack <int> store;
    int mx = 0;
    vector <int> counter(nums.size(), 0);
    bool decider = false;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            if (!store.empty()) {
                counter[store.top()] += hold;
                store.pop();
            }
            decider = true;
            
            store.push(i);
            counter[i] = hold;
            hold = 0;
        } else {
            hold++;
        }
    }        


    if (!store.empty()) {
        counter[store.top()] += hold;
        store.pop();
    }

    for (auto it: counter) {
        mx = max(mx, it);
    }

    if (decider == false) {
        mx = nums.size() - 1;
    } else if (mx == 0) {
        mx = 0;
    }

    return mx;
}

int main() {
    return 0;
}