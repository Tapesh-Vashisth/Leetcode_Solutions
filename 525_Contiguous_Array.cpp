#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findMaxLength(vector<int>& nums) {
    map <int, int> store;

    store[0] = -1;
    int current = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) { 
        if (nums[i] == 1) {
            current++;
        } else {
            current--;
        }

        if (store.find(current) != store.end()) {
            ans = max(ans, i - store[current]);
        } else {
            store[current] = i;
        }
    }

    return ans;
}

int main() {
    return 0;
}