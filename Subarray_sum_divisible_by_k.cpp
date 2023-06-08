#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByKBrute(vector<int>& nums, int k) {
    int total = 0;
    vector <int> store;
    for (int i = nums.size() - 1; i >= 0; i--) {        
        for (int j = 0; j < store.size(); j++) {
            if ((nums[i] + store[j]) % k == 0) {
                total++;
            }

            store[j] += nums[i];
        }
        
        if (nums[i] % k == 0) {
            total++;
        }
        store.push_back(nums[i]);
    }   

    return total;     
}

int subarraysDivByK(vector<int>& nums, int k) {
    int last = 0;
    vector <int> hash(k, 0);
    for (int i = 0; i < nums.size(); i++) {
        int hold = ((last + nums[i]) % k + k) % k;
        last = hold;
        hash[hold]++;
    }

    int total = 0;
    for (int i = 0; i < hash.size(); i++) {
        if (i == 0 && hash[i] >= 1) {
            total += hash[i] * (hash[i] - 1) / 2 + hash[i];
        } else {
            if (hash[i] > 1) {
                total += hash[i] * (hash[i] - 1) / 2;
            }
        }
    }

    return total;
}

int main() {
    return 0;
}