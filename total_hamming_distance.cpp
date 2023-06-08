#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// int hammingDistance(int x, int y){
//     int count = 0;
//     while (x != 0 && y != 0){
//         int bit1 = x&1;
//         int bit2 = y&1;
//         if (bit1 ^ bit2 == 1){
//             count++;
//         }
//         x = x >> 1;
//         y = y >> 1; 
//     }

//     while (x){
//         int bit = x&1;
//         if (bit == 1){
//             count++;
//         }
//         x = x >> 1;
//     }

//     while (y){
//         int bit = y&1;
//         if (bit == 1){
//             count++;
//         }
//         y = y >> 1;
//     }

//     return count;
// }

// int totalHammingDistance(vector<int>& nums){
//     int total = 0;
//     for (int i = 0; i < nums.size(); i++){
//         for (int j = i + 1; j < nums.size(); j++){
//             int value = hammingDistance(nums[i], nums[j]);
//             total = total + value;
//         }
//     }

//     return total;       
// }

int totalHammingDistance(vector <int> & nums){
    int ans = 0;
    int zero = 0;
    int one = 0;
    int max = nums[0];
    for (int i = 0; i < nums.size(); i++){
        if (max < nums[i]){
            max = nums[i];
        }
    }

    int counter = log2(max) + 1;
    // cout << counter << endl;

    for (int i = 0; i < counter; i++){
        zero = 0;
        one = 0;
        for (int j = 0; j < nums.size(); j++){
            int bit = 1&nums[j];
            if (bit == 1){
                one++;
            }else{
                zero++;
            }
            nums[j] = nums[j] >> 1; 
        }
        // cout << zero << " " << one << endl;
        ans += zero * one;
    }

    return ans;
}



int main(){
    vector <int> v = {4,14,4};
    cout << totalHammingDistance(v) << endl;
    return 0;
}