#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findMidArraySum(vector<int>& nums, int low, int mid, int high){
    int midsum = 0;
    int temp = 0;
    for (int i = mid; i <= high; i++){
        temp += nums[i];
        if (temp > midsum){
            midsum = temp;
        }
    }

    temp = midsum;

    for (int i = mid-1; i >= low; i--){
        temp += nums[i];
        if (temp > midsum){
            midsum = temp;
        }
    }

    return midsum;
}

int findSubArray(vector<int>& nums, int low, int high){
    if (low >= high){
        return nums[low];
    }else{
        int mid = (low + high)/2;
        int first = findSubArray(nums, low, mid);
        int second = findSubArray(nums, mid + 1, high);
        int middle = findMidArraySum(nums, low, mid, high);
        int greatest = max(first, max(second, middle));
        return greatest;
    }
}

int maxSubArray(vector<int>& nums) {
    int ans = findSubArray(nums, 0, nums.size() - 1);
    return ans;
}

int main(){
    vector <int> v = {5,4,-1,7,8};
    cout << maxSubArray(v) << endl;
    return 0;
}