#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int first = 0;
    int second = 0;
    auto it = nums1.begin();
    while (first < m && second < n){
        if (nums2[second] < nums1[first]){
            nums1.insert(it, nums2[second]);
            nums1.pop_back();
            first++;m++;
            second++;
        }else{
            first++;
        }
        it++;
    }

    while (first < m){
        first++;
    }

    while (second < n){
        nums1[first++] = nums2[second++];
    }

    for (int i = 0; i < nums1.size(); i++){
        cout << nums1[i] << " ";
    }
    cout << endl;
}

int main(){
    return 0;
}