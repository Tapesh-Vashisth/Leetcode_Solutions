#include <iostream>
#include <vector>
using namespace std;

    vector <int> replace(vector <int> cur, int check, int target){
        int cur_sum = 0;
        for (int i = 0; i < cur.size(); i++){
            cur_sum += cur[i];
        }

        vector <int> ret;

        int temp = cur_sum;
        for (int i = 0; i < cur.size(); i++){
            if (abs(target - cur_sum) > abs(target - ((temp - cur[i]) + check))){
                ret = cur;
                ret[i] = check;
            }
        }

        return ret;
    }

    int threeSumClosest(vector<int>& nums, int target){
        vector <vector <int>> dp;
        dp.push_back(vector <int> (nums.begin(), nums.begin() + 3));

        for (int i = 3; i < nums.size(); i++){
            vector <int> ret = replace(dp[dp.size() - 1], nums[i], target);
            dp.push_back(ret);
        }


        int ans = 0;
        for (int i = 0; i < dp[dp.size() - 1].size(); i++){
            ans += dp[dp.size() - 1][i];
        }

        return ans;
    }

int main(){
    vector <int> ans = replace(vector <int> {-3, 19, 7}, 9, 5);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}