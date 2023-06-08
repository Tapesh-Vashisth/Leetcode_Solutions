#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int crosspos(vector <int>& v){
    unordered_map <int, int> xd;
    int pos = 0;
    for (int i = 1; i < v.size(); i++){
        if (v[i] >= 0 && v[i - 1] < 0){
            pos = i;
            break;
        }
    }
    return pos;
}

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    int front = 0;
    int end = nums.size() - 1;
    int decider = 0;
    while (front < end){
        int search = -(nums[front] + nums[end]);
        int prev;
        cout << nums[front] << " " << nums[end] << endl;
        for (int i = front + 1; i < end; i++){
            cout << i << endl;
            if (i == front + 1){
                prev = nums[i];
                if (search == nums[i]){
                    ans.push_back(vector <int> {nums[front], nums[i], nums[end]});
                }
            }else{
                if (nums[i] == prev){
                    ;
                }else{
                    if (search == nums[i]){
                        ans.push_back(vector <int> {nums[front], nums[i], nums[end]});
                        prev = nums[i];
                    }   
                }
            }
        }

        if (decider == 1){
            front--;
            end--;
        }
        // front
        while (front < end && nums[front] == nums[front + 1]){
            front++;
        }

        // back 
        while (front < end && nums[end] == nums[end - 1]){
            end--;
        }


        if (decider == 1){
            decider = 0;
        }else{
            if (front < end && abs(nums[front]) < abs(nums[end])){
                end--;
            }else if (front < end && abs(nums[front]) > abs(nums[end])){
                front++;
            }else{
                if(front < end){
                    decider = 1;
                    front++;
                }
            }
        }
    }

    return ans;
}


int main(){
    vector<int> v = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector <vector<int>> ans = threeSum(v);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}