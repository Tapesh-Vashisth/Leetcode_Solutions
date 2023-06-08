#include <iostream>
#include <vector>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    vector <int> store(nums.size(), 1);
    vector <int> counter(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++) {
        int mx = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) {
                int hold = mx;
                mx = max(mx, store[j] + 1);

                store[i] = mx;

                if (store[j] + 1 >= hold) {
                    if (store[j] + 1 == hold) {
                        counter[i] += counter[j];
                    } else {
                        counter[i] = counter[j];
                    }
                }
            }
        }
    }


    int mx = 0;
    for (int i = 0; i < store.size(); i++) {
        if (store[i] > mx) {
            mx = store[i];
        }
    }

    int ans = 0;
    for (int i = 0; i < store.size(); i++) {
        if (store[i] == mx) {
            ans += counter[i];
        }
    }

    return ans;
}

int main() {
    return 0;
}