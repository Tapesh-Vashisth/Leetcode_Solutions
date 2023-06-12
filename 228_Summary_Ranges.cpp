#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector <string> ans;
    int index = 0;
    while (index < nums.size()) {
        string temp = to_string(nums[index]);
        index += 1;
        bool decider = false;
        while (index < nums.size() && (nums[index] == nums[index - 1] + 1)) {
            decider = true;
            index += 1;
        }

        if (decider) {
            temp.append("->");
            temp.append(to_string(nums[index - 1]));
        }

        ans.push_back(temp);
    }

    return ans;
}

int main() {
    return 0;
}