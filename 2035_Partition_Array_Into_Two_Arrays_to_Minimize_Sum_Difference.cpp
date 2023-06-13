#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector <int> & store, int index, int sum, vector <vector <int>> & diff, int & total, int counter) {
    if (index == store.size()) {
        diff[counter].push_back(sum - (total - sum));

        return ;
    } 

    // take 
    helper(store, index + 1, sum + store[index], diff, total, counter + 1);

    // not take 
    helper(store, index + 1, sum, diff, total, counter);
}

int minimumDifference(vector<int>& nums) {
    vector <int> first;
    vector <int> second;

    int total1 = 0;
    int total2 = 0;
    for (int i = 0; i < nums.size()/2; i++) {
        total1 += nums[i];
        first.push_back(nums[i]);

        total2 += nums[i + nums.size()/2];
        second.push_back(nums[i + nums.size()/2]);
    }

    vector <vector <int>> diff1(nums.size()/2 + 1);
    vector <vector <int>> diff2(nums.size()/2 + 1);

    helper(first, 0, 0, diff1, total1, 0);
    helper(second, 0, 0, diff2, total2, 0);

    for (int i = 0; i < diff1.size(); i++) {
        sort(diff1[i].begin(), diff1[i].end());
        sort(diff2[i].begin(), diff2[i].end());
    }

    int ans = INT32_MAX;
    for (int i = 0; i < diff1.size(); i++) {
        int lowPointer = 0;
        int highPointer = diff2[nums.size()/2 - i].size() - 1;

        while (lowPointer < diff1[i].size() && highPointer >= 0) {
            ans = min(ans, abs(diff1[i][lowPointer] + diff2[nums.size()/2 - i][highPointer]));
            if (abs(diff1[i][lowPointer]) < abs(diff2[nums.size()/2 - i][highPointer])) {
                highPointer--;
            } else {
                lowPointer++;
            }
        }

        lowPointer = 0;
        highPointer = diff1[nums.size()/2 - i].size() - 1;

        while (lowPointer < diff2[i].size() && highPointer >= 0) {
            ans = min(ans, abs(diff2[i][lowPointer] + diff1[nums.size()/2 - i][highPointer]));
            if (abs(diff2[i][lowPointer]) < abs(diff1[nums.size()/2 - i][highPointer])) {
                highPointer--;
            } else {
                lowPointer++;
            }   
        }
    }

    return ans;
}

int main() {
    return 0;
}