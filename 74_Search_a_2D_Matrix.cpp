#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<vector <int>>& nums, int rows, int columns, int k){
    int low = 0;
    int high = rows*columns - 1;
    int mid = (low + high)/2;
    while (low <= high){
        mid = (low + high)/2;
        if (nums[mid/columns][mid%columns] == k){
            return true;
        }else if (nums[mid/columns][mid%columns] > k){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int result = binary_search(matrix, n, m, target);
    return result;
}

int main(){
    vector <vector<int>> v = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    searchMatrix(v, 1);
    return 0;
}