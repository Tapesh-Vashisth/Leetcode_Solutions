#include <iostream>
#include <vector>
using namespace std;

void swap(int & first, int & second){
    int temp = first;
    first = second;
    second = temp;
}

void print(vector <int> & v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void reverse(vector <int> & value){
    int length = value.size();
    int delimit = length/2;   
    for (int i = 0; i < delimit; i = i + 1){
        char initial = value[i];
        value[i] = value[length - (i+1)];
        value[length - (i+1)] = initial;
    }
}

int issorted(vector <int> & v){
    for (int i = 0; i < v.size() - 1; i++){
        if (v[i] < v[i + 1]){
            return 0;
        }
    }
    return 1;
}


vector <int> nextPermutation(vector<int>& nums){
    if (nums.size() == 1){
        ;
    }else{
        if (issorted(nums)){
            reverse(nums);
        }else{

            int i = nums.size() - 2;
            while (i >= 0 && nums[i + 1] < nums[i]){
                i--;
            }

            int j = i + 1;
            
            while (j < nums.size() && nums[j] > nums[i]){
                j++;
            }
            j--;

            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            int hash[10] = {0};
            for (int a = i + 1; a < nums.size(); a++){
                hash[nums[a]]++;
            }

            j = i + 1;
            
            for (int a = 0; a < 10; a++){
                while (hash[a] > 0){
                    nums[j] = a;
                    hash[a]--;
                    j++;
                }
            }
        }
    }

    return nums;
}

int main(){
    vector <int> v {3, 2, 1};
    v = nextPermutation(v);
    print(v);   
    return 0;
}