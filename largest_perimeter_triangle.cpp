#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int first, int second, int third){
    if (first + second <= third || second + third <= first || first + third <= second){
        return false;
    }else{
        return true;
    }
}

int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 2; i--){
        if (check(nums[i], nums[i - 1], nums[i - 2])){
            return nums[i] + nums[i - 1] + nums[i - 2];
        }
    }
    return 0;
}

int main(){
    return 0;
}