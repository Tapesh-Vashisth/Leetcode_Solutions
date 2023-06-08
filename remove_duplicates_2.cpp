#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> s(nums.begin(), nums.end());
        return s.size();
    }
};


int main(){
    return 0;
}