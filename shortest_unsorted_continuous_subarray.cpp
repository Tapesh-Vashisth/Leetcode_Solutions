#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    vector <int> hold = nums;
    sort(hold.begin(), hold.end());

    // from start 
    int start = 0;
    for (auto i: nums) {
        if (i != hold[start]) {
            break;
        }
        start++;
    }

    // from end         
    int end = nums.size() - 1;
    for (auto i: nums) {
        if (i != hold[end]) {
            break;
        }
        end--;
    }

    return (end - start + 1);
}

int main() {
    return 0;
}