#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& nums, int first, int last, int k){
    int low = first;
    int high = last;
    int mid = (low + high)/2;
    while (low <= high){
        mid = (low + high)/2;
        if (nums[mid] == k){
            return mid;
        }else if (nums[mid] > k){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return -1;
}

int search(vector<int>& nums, int k){
    int low = 0;
    int high = nums.size() - 1;
    int mid = (low + high)/2;
    while (low <= high){
        mid = (low + high)/2;
        if (k == nums[mid]){
            return mid;
        }else{
            if (nums[low] <= nums[mid]){
                if (k <= nums[mid] && k >= nums[low]){
                    return binary_search(nums, low, mid - 1, k);
                }else{
                    low = mid + 1;
                    high = high;
                }
            }else if(nums[mid] <= nums[high]){
                if (k >= nums[mid] && k <= nums[high]){
                    return binary_search(nums, mid + 1, high, k);
                }else{
                    low = low;
                    high = mid - 1;
                }
            }else{
                if (low == mid || mid == high){
                    return -1;
                }
            }
        }
    }

    return -1;
}

int main(){
    vector <int> v = {3, 1};
    cout << search(v, 1) << endl;
    return 0;
}