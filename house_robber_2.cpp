#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums){
    vector <int> dp1 = {0, 0};

    for (int i = 0; i < nums.size() - 1; i++){
        dp1.push_back(max(dp1[dp1.size() - 2] + nums[i], dp1[dp1.size() - 1]));
    }

    vector <int> dp2 = {0, 0};
    for (int i = 1; i < nums.size(); i++){
        dp2.push_back(max(dp2[dp2.size() - 2] + nums[i], dp2[dp2.size() - 1]));
    }

    return max(dp1[dp1.size() - 1], dp2[dp2.size() - 1]);
}

int main(){
    return 0;
}