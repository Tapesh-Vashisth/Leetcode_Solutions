#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int zeros = 0;
    int product = 1;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] == 0){
            zeros++;
        }else{
            product *= nums[i];
        }
    }

    vector <int> ans;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] == 0){
            if (zeros == 1){    
                ans.push_back(product);
            }else{
                ans.push_back(0);
            }
        }else{
            if (zeros > 0){
                ans.push_back(0);
            }else{
                ans.push_back(product/nums[i]);
            }
        }
    }

    return ans;
}

int main(){
    return 0;
}