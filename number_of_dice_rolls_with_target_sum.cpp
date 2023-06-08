#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
vector <vector <int>> memory;

int helper(int cur, int n, int k, int remain){
    if (remain == 0 && cur == n){
        return 1;
    }else if(remain < 0 || cur > n){
        return 0;
    }else{
        if (memory[n][remain] != -1){
            return memory[n][remain];
        }

        int total = 0;
        for (int i = 1; i <= k; i++){
            total += helper(cur + 1, n, k, remain - i);
            total = total % mod;
        }


        memory[n][remain] = total;
        return total;
    }
}

int numRollsToTarget(int n, int k, int target){ 
    memory.resize(31);
    for (int i = 0; i < 31; i++){
        memory[i] = vector <int> (1001, -1);
    }
    int ans = helper(0, n, k, target);   
    memory.clear();
    return ans;
}

int main(){
    return 0;
}