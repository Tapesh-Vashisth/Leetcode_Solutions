#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = 0;
    int fast = 0;

    while (nums[slow] != nums[fast] || (nums[slow] == nums[fast] && slow == fast)) {
        slow = (slow + 1) % nums.size();
        fast = (fast + 2) % nums.size();
    }

    return nums[slow];

}