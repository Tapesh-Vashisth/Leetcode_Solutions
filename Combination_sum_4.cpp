#include <iostream>
#include <vector>
#include <map>
using namespace std;

int storage[1001];
int mark = 0;
int combinationSum4(vector<int>& nums, int target){
    if (target == 0){
        return 1;
    }else if(target < 0){
        return 0;
    }else{
        if (storage[target] != -1){
            return storage[target];
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            mark++;
            sum += combinationSum4(nums, target - nums[i]);
        }
        storage[target] = sum;
        return sum;
    }
}

int main(){
    for (int i = 0; i < 1001; i++){
        storage[i] = -1;
    }
    storage[0] = 1;
    vector <int> v = {1, 2, 3};
    cout << combinationSum4(v, 30) << endl;
    cout << mark << endl;
    return 0;
}