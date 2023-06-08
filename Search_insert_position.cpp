#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    if (target > nums[high]){
        return high + 1;
    }else if(target < nums[0]){
        return 0;
    }else{
        while (low < high){
            int half = (low + high)/2;
            if (nums[half] > target){
                high = half; 
            }else if(nums[half] < target){
                low = half + 1;
            }else{
                return half;
            }
        }

        return high;
    }
}

int main(){
    vector <int> v {1, 3};
    cout << searchInsert(v, 2) << endl;
    return 0;
}