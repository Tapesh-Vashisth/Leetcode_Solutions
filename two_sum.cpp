#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (target == nums[i] + nums[j]){
                    vector <int> v{i, j};
                    return v;
                }
            }
        }
    }
};

int main(){
    Solution s;
    vector <int> v{3, 2, 4};
    cout << s.twoSum(v, 6)[0] << " " << s.twoSum(v, 6)[1] << endl;
    return 0;
}
