#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums){
    unordered_map <int, int> store;
    for (int i = 0; i < store.size(); i++){
        store[nums[i]]++;
    }

    auto it = store.begin();

    for (; it != store.end(); it++){
        if ((*it).second > (nums.size()/2)){
            return (*it).first;
        }
    }
}

int main(){
    return 0;
}