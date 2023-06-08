#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector <unordered_map <int, int>> memory; 

int helper(vector <int>& nums, int index, int target, int value){
    if (index > nums.size() - 1){
        if (value == target){
            return 1;
        }else{
            return 0;
        }
    }else{
        if (memory[index].find(value) != memory[index].end()){
            return memory[index][value];
        }
        
        int counter = 0; 
        counter += helper(nums, index + 1, target, value + nums[index]); 
        counter += helper(nums, index + 1, target, value - nums[index]);
        memory[index].insert({value, counter});
        return counter;
    }
    
}

int findTargetSumWays(vector<int>& nums, int target){
    memory.clear();
    memory.resize(21);
    int ans = helper(nums, 0, target, 0);
    return ans;
}

int main(){
    return 0;
}