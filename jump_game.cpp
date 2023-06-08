#include <iostream>
#include <vector>
using namespace std;

vector <int> memory;

bool helper(vector <int>& nums, int index){
    if (index == nums.size() - 1){
        return true;
    }else if (index > nums.size() - 1){
        return false;
    }else{
        if (memory[index] != -1){
            return memory[index];
        }
        
        bool decider = false;
        for (int i = 1; i <= nums[index]; i++){
            bool temp = helper(nums, index + i);
            if (temp == true){
                decider = true;
                break;
            }
        }

        return decider;
    }
}

bool canJump(vector<int>& nums){
    memory.resize(10001);
    fill(memory.begin(), memory.end(), -1);
    bool ans = helper(nums, 0);
    memory.clear();
    return ans;
}

int main(){
    return 0;
}