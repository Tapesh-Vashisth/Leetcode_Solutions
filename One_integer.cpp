#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int total = 0;
    vector <int>:: iterator it;
    while (nums.size() != 1){
        // for (int i = 0; i < nums.size(); i++){
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        int temp = nums[0] + nums[1];
        total = total + temp;
        nums.erase(nums.begin());
        nums.erase(nums.begin());
        it = nums.begin();
        while (it != nums.end() && temp > (*it)){
            it++;
        }
        nums.insert(it, temp);
    }

    return total;
}

int main(){
    vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << solve(v) << endl;
    return 0;
}