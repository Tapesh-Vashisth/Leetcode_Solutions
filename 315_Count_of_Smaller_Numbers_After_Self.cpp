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
                x += (x) & (-x);
            }
        }

        int sum(int x) {
            x++;

            int ans = 0;
            while (x) {
                ans += fn[x];
                x -= (x) & (-x);
            }

            return ans;
        }
};

vector<int> countSmaller(vector<int>& nums) {
    vector <int> keep = nums;
    sort(keep.begin(), keep.end());
    auto last = unique(keep.begin(), keep.end());

    keep.resize(distance(keep.begin(), last));

    for (int i = 0; i < nums.size(); i++) {
        int pos = lower_bound(keep.begin(), keep.end(), nums[i]) - keep.begin();
        nums[i] = pos;
    }

    fenwick ftree(keep.size() + 1);

    for (auto it: nums) {
        ftree.add(it, 1);
    }

    vector <int> ans;

    for (auto it: nums) {
        ftree.add(it, -1);
        ans.push_back(ftree.sum(it - 1));
    }

    return ans;
}

int main() {
    return 0;
}