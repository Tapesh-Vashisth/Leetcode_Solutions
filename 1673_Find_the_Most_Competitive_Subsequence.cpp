#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> mostCompetitive(vector<int>& nums, int k) {
    deque <int> store;

    vector <int> ans;
    for (int i = 0; i < nums.size(); i++) {
        while (!store.empty() && store.back() > nums[i]) {
            store.pop_back();
        }

        store.push_back(nums[i]);

        if (k - ans.size() >= nums.size() - i) {
            ans.push_back(store.front());
            store.pop_front();
        }
    }

    return ans;
}

int main() {
    return 0;
}