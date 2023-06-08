#include <iostream>
#include <vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums){
    vector <bool> hmap(nums.size() + 1, true);
    int decider = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++){
        if (hmap[nums[i]]){
            decider = decider ^ nums[i] ^ nums[i];
            hmap[nums[i]] = false;
        }else{
            decider = decider ^ nums[i];
        }
        sum += nums[i];
    }

    int total = (nums.size()*(nums.size() + 1))/2;
    int missing = total - (sum - decider);
    vector <int> ans = {decider, missing};
    return ans;
}

int main(){
    return 0;
}