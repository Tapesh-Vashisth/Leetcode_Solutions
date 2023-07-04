#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int counter[32];
    int i, j;
    int res = 0;
    
    for(i=0; i<32; i++)
        counter[i] = 0;
        
    for(i=0; i<nums.size(); i++)
    {
        for(j=0; j<32; j++)
        {
            if(nums[i] & (1<<j))
                counter[j]++;
        }
    }
    
    for(i=0; i<32; i++)
    {
        if(counter[i]%3)
            res |= 1<<i;
    }
    
    return res;
}

int main() {
    return 0;
}