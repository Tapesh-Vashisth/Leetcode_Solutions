#include <iostream>
#include <vector>
using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries){
    int sum = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] % 2 == 0){
            sum += nums[i];
        }
    }

    vector <int> ans;

    for (int i = 0; i < queries.size(); i++){
        int holder = nums[queries[i][1]];
        nums[queries[i][1]] += queries[i][0];
        if (nums[queries[i][1]] % 2){
            sum += queries[i][0];
        }else{
            sum -= holder;
        }

        ans.push_back(sum);
    }

    return ans;
}

int main(){
    
    return 0;
}