#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool canJump(vector<int>& nums){
    int limit = nums[0];
    for (int i = 1; i < nums.size(); i++){
        if (limit < i){
            return false;
        }else{
            if (i + nums[i] > limit){
                limit = i + nums[i];
            }
        }
    }

    return true;
}

int main(){

    return 0;
}