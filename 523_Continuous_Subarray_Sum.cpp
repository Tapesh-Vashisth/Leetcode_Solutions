#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int store = 0;
    map <int, int> mapping;
    for (int i = 0; i < nums.size(); i++) {
        int hold = (store + nums[i]) % k;
        if (mapping[hold] == 0) {
            if (hold == 0) {
                if (i >= 1) {
                    return true;
                }
            } else {
                mapping[hold] = i + 1;
            }

        } else {
            if (i - (mapping[hold] - 1) + 1 >= 3) {
                return true;
            }
        }
        store = hold;
    }        

    return false;
}

int main(){
    return 0;
}