#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int mnPosIndex = nums.size();
    int mxNegIndex = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            mxNegIndex = i;
        } else {
            mnPosIndex = i;
            break;
        }
    }

    vector <int> ans;

    while (mxNegIndex >= 0 && mnPosIndex < nums.size()) {
        if (abs(nums[mxNegIndex]) > abs(nums[mnPosIndex])) {
            ans.push_back(nums[mnPosIndex] * nums[mnPosIndex]);
            mnPosIndex++;
        } else {
            ans.push_back(nums[mxNegIndex] * nums[mxNegIndex]);
            mxNegIndex--;
        }
    }

    while (mxNegIndex >= 0) {
        ans.push_back(nums[mxNegIndex] * nums[mxNegIndex]);
        mxNegIndex--;
    }

    while (mnPosIndex < nums.size()) {
        ans.push_back(nums[mnPosIndex] * nums[mnPosIndex]);
        mnPosIndex++;
    }

    return ans;
}


int main() {
    return 0;
}