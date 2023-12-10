#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector <int> ans;

    vector <int> prefixSum = {0};
    for (int i = 0; i < nums.size(); i++) {
        prefixSum.push_back(prefixSum[prefixSum.size() - 1] + nums[i]);
    }

    for (int i = 0; i < nums.size(); i++) {
        ans.push_back(((i * nums[i]) - prefixSum[i]) + ((prefixSum[prefixSum.size() - 1] - prefixSum[i]) - ((nums.size() - i) * (nums[i]))));
    }

    return ans;
}

int main() {
    return 0;
}