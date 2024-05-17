#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector <int> ans(nums.size());

    int first = 0;
    int second = 1;

    for (auto it: nums) {
        if (it > 0) {
            ans[first] = it;
            first += 2;
        } else {
            ans[second] = it;
            second += 2;
        }
    }        

    return ans;
}

int main() {
    return 0;
}