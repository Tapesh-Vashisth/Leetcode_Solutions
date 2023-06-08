#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

inline int power(int a, int b)
{
       int x = 1;
       while (b)
       {
               if (b & 1) x *= a;
               a *= a;
               b >>= 1;
       }
       return x;
}

vector<vector<int>> subsets(vector<int>& nums){
    vector <vector<int>> v;
    int total = power(2, nums.size());
    for (int i = 0; i < total; i++){
        int temp = i;
        vector <int> holder;
        int index = 0;
        while (temp){
            int bit = temp & 1;
            if (bit == 1){
                holder.push_back(nums[index]);
            }
            index++;
            temp = temp >> 1;
        }
        cout << endl;

        v.push_back(holder);
    }

    return v;
}

int main(){
    vector <int> v = {1, 2, 3};
    subsets(v);
    return 0;
}