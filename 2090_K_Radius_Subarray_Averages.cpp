#include <iostream>
#include <vector>
using namespace std;

vector<int> getAverages(vector<int>& nums, int k) {
    vector <long long> prefixSum(nums.size() + 1, 0);

    for (int i = 0; i < nums.size(); i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }   


    vector <int> ans;

    for (int i = 0; i < nums.size(); i++) {
        if (i - k >= 0 && i + k < nums.size()) {
            ans.push_back((prefixSum[i + k + 1] - prefixSum[i - k])/(2*k + 1));
        } else {
            ans.push_back(-1);
        }
    }

    return ans;
}

int main() {
    return 0;
}