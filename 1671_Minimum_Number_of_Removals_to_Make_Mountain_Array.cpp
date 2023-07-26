#include <iostream>
#include <vector>
#include <set>
using namespace std;

int minimumMountainRemovals(vector<int>& nums) {
    vector <int> front;
    vector <int> back(nums.size());

    for (int i = 0; i < nums.size(); i++) {
        int mx = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] > nums[j]) {
                mx = max(mx, front[j]);
            }
        }

        front.push_back(mx + 1);
    }

    for (int i = nums.size() - 1; i >= 0; i--) {
        int mx = 0;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) {
                mx = max(mx, back[j]);
            }
        }

        back[i] = (mx + 1);
    }

    set <pair <int, int>> storeBack;
    set <pair <int, int>> storeFront;
    for (int i = 0; i < back.size(); i++) {
        storeBack.insert({back[i], i});
    }

    int ans = 0;

    for (int i = 0; i < front.size(); i++) {
        storeFront.insert({front[i], i});
        storeBack.erase({back[i], i});
        pair <int, int> holdFirst = (*(--storeFront.end()));
        int first = holdFirst.first;

        if (i != front.size() - 1) {
            pair <int, int> hold = (*(--storeBack.end()));
            int second = nums[hold.second] != nums[holdFirst.second] ? hold.first : hold.first - 1; 
            if (first == 1) {
                if (nums[holdFirst.second] < nums[hold.second]) {
                    ans = max(ans, first + second);
                }
            } else if (second <= 1) {
                if (nums[hold.second] < nums[holdFirst.second]) {
                    ans = max(ans, first + second);
                }
            } else {
                ans = max(ans, first + second);
            }
        }
    }

    return nums.size() - ans;
}


int main() {
    return 0;
}