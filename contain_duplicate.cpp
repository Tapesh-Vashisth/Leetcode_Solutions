#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums){
    unordered_map <int, int> m;
    for (int i = 0; i < nums.size(); i++){
        m[nums[i]]++;
        if (m[nums[i]] > 1){
            return true;
        }
    }

    return false;
}

int main(){
    return 0;
}