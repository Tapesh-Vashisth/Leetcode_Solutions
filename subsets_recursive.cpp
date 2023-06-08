#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums){
    vector <vector <int>> result = {{}};
    if (nums.empty()){
        return result;
    }else{
        vector <int> pass(nums.begin() + 1, nums.end());
        result = subsets(pass);
        vector <vector <int>> resultw;
        int counter = count(nums.begin() + 1, nums.end(), nums[0]);
        if (counter == 0){
            // cout << "hi" << endl;
            resultw = result;
        }else{
            // cout << "h" << endl;
            for (int i = 0; i < result.size(); i++){
                if (count(result[i].begin(), result[i].end(), nums[0]) == counter){
                    resultw.push_back(result[i]);
                }
            }
        }

        for (int i = 0; i < resultw.size(); i++){
            resultw[i].push_back(nums[0]);
        }

        result.insert(result.end(), resultw.begin(), resultw.end());

        return result;
    }
}

int main(){
    vector <int> v = {1, 2, 2, 2, 2};
    vector <vector <int>> ans = subsets(v);
    for (auto a: ans){
        for (auto x: a){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}