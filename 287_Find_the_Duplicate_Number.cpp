#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int num = nums[0];
    int idx = 0;
    while(nums[idx] != -1){
        num = nums[idx];
        nums[idx] = -1;
        idx = num;
    }

    return num;
}

int main() {
    return 0;
}