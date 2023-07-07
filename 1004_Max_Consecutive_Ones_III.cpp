#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {    
    // true 
    int mx = 0;
    int current = 0;
    int currentk = 0;
    int low = 0;
    int high = 0;

    while (high < nums.size()) {
        if (currentk <= k) {
            if (nums[high] == 1) {
                ;
            } else {
                currentk++;
            }

            current++;
            high++;
        } else {
            if (nums[low] == 1) {
                ;
            } else {
                currentk--;
            }

            current--;

            low++;
        }

        if (currentk <= k) {
            mx = max(mx, current); 
        }
    }

    return mx;
}

int main() {
    return 0;
}