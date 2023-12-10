#include <iostream>
#include <vector>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    vector <int> hash(101, 0);

    for (auto it: nums) {
        hash[it]++;
    }        

    int ans = 0;

    for (auto it: hash) {
        ans += (it) * (it - 1) / 2;
    }

    return ans;
}

int main() {
    return 0;
}