#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0 && nums[i] < nums.size()) {
            int temp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = temp;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

int main() {
    return 0;
}