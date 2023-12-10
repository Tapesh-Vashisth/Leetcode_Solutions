#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int low = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            int temp = nums[low];
            nums[low] = nums[i];
            nums[i] = temp;
            low++;
        }
    }    

    return nums;    
}

int main() {
    return 0;
}