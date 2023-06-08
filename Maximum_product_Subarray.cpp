#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INT_MIN 1>>31;

int maxProduct(vector<int>& nums){
    int no_of_minuses = 0;
    vector <int> dp = {0};
    int absmul = 1;

    for (int i = nums.size() - 1; i >= 0; i--){
        if (nums[i] == 0){
            absmul = 1;
            dp.push_back(0);
            no_of_minuses = 0;
        }else if(nums[i] > 0){
            absmul *= nums[i];
            int hold = nums[i] * dp[nums.size() - (i + 1)];
            if (hold > nums[i]){
                dp.push_back(hold);
            }else{
                dp.push_back(nums[i]);
            }
        }else{
            absmul *= abs(nums[i]);
            no_of_minuses += 1;
            if (no_of_minuses % 2 == 0){
                dp.push_back(absmul);
            }else{
                dp.push_back(nums[i]);
            }
        }

        for (int i = 0; i < dp.size(); i++){
            cout << dp[i] << " ";
        }
        cout << endl;
    }

    int m = INT_MIN;

    for (int i = 0; i < dp.size(); i++){
        if (dp[i] > m){
            m = dp[i];
        }
    }

    return m;
}

int main(){
    vector <int> v = {-1, 0, 2, 0, 5, -3, -6, 8};
    cout << maxProduct(v) << endl;
    return 0;
}