#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    map <int, int> store;

    for (auto it: nums) {
        store[it]++;
    }   

    vector <int> ans;        

    for (auto it: store) {
        if (it.second > nums.size() / 3) {
            ans.push_back(it.first);
        }
    }

    return ans;
}

int main() {
    return 0;
}