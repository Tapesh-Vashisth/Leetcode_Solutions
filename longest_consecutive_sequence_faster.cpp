#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map <int, int> store;
    int hold = 0;
    deque <int> q;
    for (int i = 0; i < nums.size(); i++) {
        store[nums[i]] = store[nums[i] + 1] + store[nums[i] - 1] + 1;
        store[nums[i] + store[nums[i] + 1]] = store[nums[i]];
        store[nums[i] - store[nums[i] - 1]] = store[nums[i]];

        if (store[nums[i]] > hold) {
            hold = store[nums[i]];
        }
    }

    return hold;
}

int main() {

    return 0;
}