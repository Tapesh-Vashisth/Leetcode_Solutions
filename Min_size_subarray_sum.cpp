#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    vector <int> prefix_sum = {0};
    for (int i = 0; i < nums.size(); i++){
        prefix_sum.push_back(prefix_sum[prefix_sum.size() - 1] + nums[i]);
    }        

    int mn = 0;

    for (int i = 0; i < prefix_sum.size(); i++){
        cout << prefix_sum[i] << " ";
    }

    cout << endl;

    for (int i = 1; i < prefix_sum.size(); i++){
        int findout = prefix_sum[i] - target;
        if (findout >= 0){
            auto it = lower_bound(prefix_sum.begin(), prefix_sum.begin() + i, findout);
            int index = (it - prefix_sum.begin() - 1);
            cout << index << endl;
        }
    }

    return mn;
}

int main(){
    return 0;
}