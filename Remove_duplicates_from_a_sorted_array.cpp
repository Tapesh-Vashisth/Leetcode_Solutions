#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int aggressor = 1;
        int predessor = 0;
        int i = 0;
        int len = nums.size();
        while (i < len - 1){
            if (nums[aggressor] == nums[predessor]){
                int j = aggressor;
                while (nums[predessor] == nums[j] && j < len){
                    int imp = j + 1;
                    while (imp < len){
                        // cout << "hi" << endl;
                        nums[imp - 1] = nums[imp];
                        imp++;
                    }
                    len--;
                }
                predessor++;
                aggressor++;
            }else{
                predessor++;
                aggressor++;
            }
            i++;
        }
        return len;
    }
};


int main(){
    vector <int> v{1, 2, 2};
    Solution s;
    int size = s.removeDuplicates(v);
    cout << size << endl;
    for (int i = 0; i < size; i++){
        cout << v[i] << endl;
    }
    return 0;
}