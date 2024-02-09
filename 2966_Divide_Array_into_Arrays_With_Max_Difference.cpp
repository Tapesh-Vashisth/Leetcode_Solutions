#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    vector <vector <int>> ans;
    sort(nums.begin(), nums.end());

    int index = 0;

    while (index < nums.size()) {
        int hold = nums[index];
        bool decider = true;
        vector <int> temp;
        for (int i = index; i < index + 3; i++) {
            if (nums[i] - nums[index] > k) {
                decider = false;
                break;
            } 

            temp.push_back(nums[i]);
        }

        if (!decider) {
            vector <vector <int>> realans;
            return realans;
        } else {
            ans.push_back(temp);
        }

        index += 3;
    }

    return ans;
}
    
int main() {
    return 0;
}