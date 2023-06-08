#include <iostream>
#include <vector>
using namespace std;

int maxCommon(vector <int>& nums1, vector <int>& nums2){
    int p = nums2.size() - 1;
    int ans = 0;
    while (p >= 0){
        int counter = 0;
        for (int i = 0; i + p < nums2.size() && i < nums1.size(); i++){
            cout << nums1[i] << " " << nums2[i + p] << endl;
            if (nums2[i] == nums1[i + p]){
                cout << "hi" << endl;
                counter++;
            }else{
                break;
            }
        }

        if (counter > ans){
            ans = counter;
        }

        p--;
    }
    return ans;
}

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int first = maxCommon(nums1, nums2);
    cout << first << endl;
    int second = maxCommon(nums2, nums1);
    return max(first, second);
}

int main(){
    vector <int> v1 = {0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3};
    vector <int> v2 = {1, 1, 3, 3, 3, 3, 3, 3, 3};
    cout << findLength(v1, v2) << endl;
    return 0;
}