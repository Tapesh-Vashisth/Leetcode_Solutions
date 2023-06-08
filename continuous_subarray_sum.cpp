#include <iostream>
#include <vector>
using namespace std;

vector <int> prefix_sum;

bool check_helper(int k, int current){
    bool ans = false;
    for (int i = current + 1; i < prefix_sum.size(); i++){
        int hold = prefix_sum[i] - prefix_sum[current];
        if (hold % k == 0 && i - current > 1){
            ans = true;
            break;
        }else{
            bool hold = check_helper(k, i);
        }
    }

    return ans;
}

void fill_prefix(vector <int>& nums){
    prefix_sum.push_back(0);
    for (int i = 0; i < nums.size(); i++){
        prefix_sum.push_back(prefix_sum[i - 1] + nums[i]);
    }
}

bool checkSubarraySum(vector<int>& nums, int k) {
    prefix_sum.clear();
    fill_prefix(nums);
    return check_helper(k, 0);
}

int main(){
    return 0;
}