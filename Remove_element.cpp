#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val){
    int ans = nums.size();
    int i = 0;
    int len = nums.size();
    while (i < len){
        if (nums[i] == val){
            ans--;
            if (i == len - 1){
                break;
            }else{
                for (int j = i; j < len - 1; j++){
                    nums[j] = nums[j + 1];
                }
            }
            len--;
        }else{
            i++;
        }
    }
    return ans;
}

int main(){
    vector <int> v = {3, 2, 2, 3};
    cout << removeElement(v, 3) << endl;
    return 0;
}