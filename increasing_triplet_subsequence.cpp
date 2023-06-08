#include <iostream>
#include <vector>
using namespace std;

bool increasingTriplet(vector<int>& nums){
    vector <int> left_minimum = {nums[0]};
    vector <int> right_maximum = {nums[nums.size() - 1]};
    for (int i = 1; i < nums.size(); i++){
        int from_back = nums.size() - i - 1;
        if (left_minimum[left_minimum.size() - 1] > nums[i]){
            left_minimum.push_back(nums[i]);
        }

        if (nums[from_back] > right_maximum[right_maximum.size() - 1]){
            right_maximum.push_back(nums[from_back]);
        }
    }

    for (int i = 0; i < left_minimum.size(); i++){
        cout << left_minimum[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < right_maximum.size(); i++){
        cout << right_maximum[i] << " ";
    }
    cout << endl;

    return true;
}

int main(){
    return 0;
}