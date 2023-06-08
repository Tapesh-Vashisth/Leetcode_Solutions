#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> helper(vector <int>& candidates, int target, int current){
    if (target < 0 ){
        vector <vector <int>> ans;
        return ans;
    }else if(target == 0){
        vector <vector <int>> ans = {};
        return ans;
    }else{
        int hash[52] = {0};
        vector <vector <int>> ans;
        for (int i = current + 1; i < candidates.size(); i++){
            if (hash[i] == 0){
                hash[i] = 1;
                vector <vector <int>> temp = helper(candidates, target, i);
                for (int i = 0; i < temp.size(); i++){
                    temp[i].push_back(candidates[i]);
                }
                ans.insert(ans.begin(), temp.begin(), temp.end());
            }
        }
        return ans;
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector <vector <int>> ans = helper(candidates, target, 0);
    return ans;
}

int main(){
    return 0;
}