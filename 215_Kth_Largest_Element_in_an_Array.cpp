#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void bubble_sort(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++){
        for (int j = 0; j < nums.size() - 1; j++){
            if (nums[j] > nums[j + 1]){
                int temp = nums[j];
                nums[j] = nums[j + 1];    
                nums[j + 1] = temp;
            }
        }    
    }
}

void insertion_sort(vector<int>& nums){
    for (int i = 1; i < nums.size(); i++){
        int j = i;
        while (j > 0 && nums[j] < nums[j - 1]){
            int temp = nums[j - 1];
            nums[j - 1] = nums[j];
            nums[j] = temp;
            j--;
        }
    }
}

void selection_sort(vector<int>& nums){
    int index = 0;
    for (int i = 0; i < nums.size(); i++){
        int min = i;
        for (int j = i; j < nums.size(); j++){
            if (nums[min] > nums[j]){
                min = j;
            }
        }
        int temp = nums[min];
        nums[min] = nums[i];
        nums[i] = temp;
    }
}

void counting_sort(vector<int>& nums){
    int max = nums[0];
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] > max){
            max = nums[i];
        }
    }


    vector <int> v(max + 1, 0);
    for (int i = 0; i < nums.size(); i++){
        v[nums[i]]++;
    }

    int index = 0;
    for (int i = 0; i < max + 1; i++){
        if (v[i] > 0){
            while (v[i] > 0){
                nums[index++] = i;
                v[i]--;
            }
        }
    }

}

void quicksort(vector<int> & v, int low, int high){
    if (low < high){
        int small = low;
        for (int i = low; i < high; i++){
            if (v[i] <= v[high]){
                if (small < i){
                    int temp = v[small];
                    v[small] = v[i];
                    v[i] = temp;
                }
                small++;
            }
        }
        
        int temp = v[small];
        v[small] = v[high];
        v[high] = temp;

        quicksort(v, low, small - 1);
        quicksort(v, small + 1, high);
    }
}

int quickselect(vector<int> v, int low, int high, int k){
    if (low < high){
        cout << low << " " << high << endl;
        int small = low;
        for (int i = low; i < high; i++){
            // cout << v[i] << " " << v[high] << endl;
            if (v[i] < v[high]){
                if (small < i){
                    int temp = v[small];
                    v[small] = v[i];
                    v[i] = temp;
                }
                small++;
            }
        }
        int temp = v[small];
        v[small] = v[high];
        v[high] = temp;
        // print(v);
        // cout << small << endl;
        if (v.size() - small == k){
            // cout << v[small] << endl;
            return v[small];
        }else{
            if (v.size() - small < k){
                return quickselect(v, low, small - 1, k);
            }else{
                return quickselect(v, small + 1, high, k);
            }
        }

    }else if(high == low){
        return v[low];
    }else{
        return -1;
    }
}




int findKthLargest(vector<int>& nums, int k){
    int ans = quickselect(nums, 0, nums.size() - 1, k);
    return ans;
}





int partition(vector <int> & nums, int low, int high, int pivot) {
    int temp = nums[low];
    nums[low] = nums[pivot];
    nums[pivot] = temp;

    int part = low + 1;
    for (int i = low + 1; i <= high; i++) {
        if (nums[i] <= nums[low]) {
            temp = nums[i];
            nums[i] = nums[part];
            nums[part] = temp;
            part++;
        }
    }

    temp = nums[low];
    nums[low] = nums[part - 1];
    nums[part - 1] = temp;
    return nums.size() - part + 1;
}


int helper(vector <int> & nums, int low, int high, int k) {
    if (low <= high) {
        int mid = low + (high - low)/2;

        int temp = nums[mid];
    
        int hold = partition(nums, low, high, mid);

        if (hold == k) {
            return temp;
        } else if (hold < k) {
            return helper(nums, low, nums.size() - hold - 1, k);
        } else {
            return helper(nums, nums.size() - hold + 1, high, k);
        }
    }

    return -1;
}

int findKthLargest(vector<int>& nums, int k) {
    return helper(nums, 0, nums.size() - 1, k);
}


int main(){
    vector <int> v = {3,2,3,3,2,4,5,5,1};
    cout << findKthLargest(v, 10) << endl;
    return 0;
}