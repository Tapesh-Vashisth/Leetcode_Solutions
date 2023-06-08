#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue <int> store;
    unordered_map <int, int> mapped;
    for (int i = 0; i < k; i++) {
        store.push(nums[i]);
        mapped[nums[i]]++;
    }

    vector <int> ans;

    for (int i = k; i < nums.size(); i++) {
        if (mapped[store.top()] > 0) {
            ans.push_back(store.top());
        } else {
            while (mapped[store.top()] <= 0) {
                store.pop();
            }
            ans.push_back(store.top());
        }

        mapped[nums[i - k]]--;
        mapped[nums[i]]++;        
    }

    return ans;
}


// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     multiset <int> store;
//     for (int i = 0; i < k; i++) {
//         store.insert(nums[i]);
//     }

//     vector <int> ans;
//     int del = 0;
//     for (int i = k; i < nums.size(); i++) {
//         ans.push_back(*(--store.end()));
//         int hold = store.erase(nums[del]);
//         for (int i = 0; i < hold - 1; i++) {
//             store.insert(nums[del]);
//         }
//         store.insert(i);
//         del++;
//     }

//     ans.push_back(*(--store.end()));

//     return ans;
// }

int main() {
    return 0;
}