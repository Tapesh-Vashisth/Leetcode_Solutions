#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lower_index_binary_search(vector <int>& arr, int x){
    int low = 0;
    int high = arr.size();
    int mid = (high + low)/2;
    while (low <= high){
        mid = (high + low)/2;
        if (x > arr[mid]){
            low = mid + 1;
        }else if(x < arr[mid]){
            high = mid - 1;
        }else{
            return mid;
        }
    }
    if (high == -1){
        return 0;
    }else if(high == arr.size()){
        return high - 1;
    }else{
        return high;
    }
}

vector<int> findClosestElements(vector<int>& arr, int k, int x){
    vector <int> v;
    int target = lower_index_binary_search(arr, x);
    cout << target << endl;
    int right = target + 1;
    int left = target;
    for (int i = 0; i < k; i++){
        cout << left << " " << right << endl;
        if (left < 0){
            v.push_back(arr[right]);
            right++;
        }else if(right > arr.size() - 1){
            v.push_back(arr[left]);
            left--;
        }else{
            if (abs(x - arr[left]) > abs(x - arr[right])){
                if (left == right){
                    v.push_back(arr[right]);
                    right++;
                    left--;
                }else{
                    v.push_back(arr[right]);
                    right++;
                }
            }else{
                if (left == right){
                    v.push_back(arr[left]);
                    right++;
                    left--;
                }else{
                    v.push_back(arr[left]);
                    left--;
                }
            }
        }
    }

    sort(v.begin(), v.end());

    return v;
}

int main(){
    vector <int> v = {3, 5, 8, 10};
    v = findClosestElements(v, 2, 15);
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}