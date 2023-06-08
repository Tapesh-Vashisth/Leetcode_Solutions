#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k){
    unordered_map <int, vector <int>> pos;
    for (int i = 0; i < nums.size(); i++){
        pos[nums[i]].push_back(i);
    }

    auto it = pos.begin();

    for (; it != pos.end(); it++){
        for (int j = 0; j < (*it).second.size() - 1; j++){
            if ((*it).second[j + 1] - (*it).second[j] <= k){
                return true;
            }
        }
    }

    return false;
}

int main(){

}