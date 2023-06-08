#include <iostream>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    int mn = INT32_MAX;
    int mx = INT32_MIN;

    for (int i = 0; i < nums.size(); i++) {
        mn = min(mn, nums[i]);
        mx = max(mx, nums[i]);
    }

    vector <int> store(abs(mn) + abs(mx) + 5, 0);

    int size = 0;
    for (int i = 0; i < nums.size(); i++) {
        store[nums[i] + abs(mn)]++;
        size = max(size, store[nums[i] + abs(mn)]);
    }

    vector <vector <int>> freq(size + 1);

    for (int i = 0; i < store.size(); i++) {
        if (store[i] > 0) {
            freq[store[i]].push_back(i - abs(mn));
        }
    }

    vector <int> ans;
    int counter = 0;
    for (int i = freq.size() - 1; i >= 0; i--) {
        for (int j = 0; j < freq[i].size(); j++) {
            if (counter >= k) {
                break;
            }
            ans.push_back(freq[i][j]);
            counter++;
        }

        if (counter >= k) {
            break;
        }
    }

    return ans;
}

int main() {
    return 0;
}