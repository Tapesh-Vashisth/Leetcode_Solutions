#include <iostream>
#include <vector>
#include <map>
using namespace std;

int minimumIndex(vector<int>& nums) {
    int dominant = -1;
    map <int, int> mapped;
    for (auto it: nums) {
        mapped[it]++;
        if (mapped[it] * 2 > nums.size()) {
            dominant = it;
        }
    }       
    
    int total = mapped[dominant];
    
    int current = 0;
    for (int i = 0; i < nums.size(); i++) {
        int firstSize = i + 1;
        int secondSize = nums.size() - i - 1;
        
        if (nums[i] == dominant) {
            current++;
        }
        
        if (current * 2 > firstSize && ((total - current) * 2) > secondSize) {
            return i;
        } 
    }
    
    return -1;
}

int main() {
    return 0;
}