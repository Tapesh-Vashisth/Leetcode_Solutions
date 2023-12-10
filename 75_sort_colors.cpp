#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int first = 0;
    int second = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            int temp = nums[first];
            nums[first] = nums[i];
            nums[i] = temp;
            first++;

            temp = nums[second];
            nums[second] = nums[i];
            nums[i] = temp;
            second++;

        } else if (nums[i] == 1) {
            int temp = nums[second];
                nums[second] = nums[i];
                nums[i] = temp;
                second++;
        }
    }
}

int main() {
    return 0;
}