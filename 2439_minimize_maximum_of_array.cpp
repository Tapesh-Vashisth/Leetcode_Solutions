#include <iostream>
#include <vector>
using namespace std;

int minimizeArrayValue(vector<int>& nums) {
    int ans = 0;
    int space = 0;
    for (int i = 0; i < nums.size(); i++) {
        int remain = (ans - nums[i]);
        if (remain >= 0) {
            space += ans - nums[i];
        } else {
            int sub = min(remain, space);
            remain -= sub;
            space -= sub;

            int boxes = i + 1;
            int mul = remain/boxes;
            int rem = remain % boxes;
            ans += mul + (rem > 0 ? 1: 0);
            space += boxes - rem;
        }
    }

    return ans;
}

int main() {
    return 0;
}