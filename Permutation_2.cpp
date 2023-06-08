#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
int valid[] = {0, 0, 0, 0, 0, 0};
vector <int> temp;
void permute(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++){
        if (temp.size() == nums.size() && i == 0){
            ans.push_back(temp);
        }else{
            if (valid[i] == 0){
                int decider = 0;
                // cout << decider << endl;
                for (int j = 0; j < i; j++){
                    if (nums[i] == nums[j] && valid[j] == 0){
                        decider = 1;
                        break;
                    }
                }
                // cout << decider << endl;
                if (decider == 0){
                    cout << i << endl;
                    temp.push_back(nums[i]);
                    valid[i] = 1;
                    permute(nums);
                    temp.pop_back();
                    valid[i] = 0;   
                }
            }
        }
    }
}

int main(){
    vector <int> a = {1, 1, 2};
    permute(a);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}