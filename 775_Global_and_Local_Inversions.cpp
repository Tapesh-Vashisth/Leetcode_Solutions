#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class fenwick {
    public: 
        vector <int> fn;
        int n;

        fenwick(int n) {
            this->n = n + 1;
            fn.resize(this->n, 0);
        }

        void add(int x, int y) {
            x++;
            
            while (x < n) {
                fn[x] += y;
                x += (x & (-x));
            }
        }

        int sum(int x) {
            x++;

            int ans = 0;
            while (x) {
                ans += fn[x];
                x -= (x & (-x));
            }

            return ans;
        }

        int sum(int l, int r) {
            return sum(r) - sum(l - 1);
        }
};

bool isIdealPermutation(vector<int>& nums) {
    fenwick ftree(nums.size());
    vector <pair <int, int>> store;
    for (int i = 0; i < nums.size(); i++) {
        store.push_back({nums[i], i});
    }

    sort(store.begin(), store.end());


    long long global = 0;

    for (int i = 0; i < store.size(); i++) {
        global += ftree.sum(store[i].second, store.size() - 1);
        ftree.add(store[i].second, 1);
    }

    long long local = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            local++;
        }
    }

    return local == global;
}

int main() {
    return 0;
}