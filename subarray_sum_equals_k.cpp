#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int last = 0;
    unordered_map <long long, int> store;
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
        long long hold = last + nums[i];
        bool decider = store.find(hold - k) == store.end();

        if (decider) {
            ;
        } else {
            int counter = store[hold - k];
            total += (counter + 1) * counter / 2;
        }

        store[hold]++;
        last = hold;
    }

    return total;
}

int main() {
    return 0;
}