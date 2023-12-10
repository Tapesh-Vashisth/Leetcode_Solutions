#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int maximumScore(vector<int>& nums, int k) {
    stack <int> s;
    vector <int> max_left;
    vector <int> max_right;
    vector <int> min_left;
    vector <int> min_right;

    s = stack<int>();
    // min_left 
    for (int i = 0; i < nums.size(); i++) {
        if (s.empty()) {
            min_left.push_back(-1);
            s.push(i);
        } else {
            if (nums[s.top()] < nums[i]) {
                min_left.push_back(s.top());
                s.push(i);
            } else {
                while (!s.empty() && nums[s.top()] >= nums[i]) {
                    s.pop();
                }
    
                if (s.empty()) {
                    min_left.push_back(-1);
                    s.push(i);
                } else {
                    min_left.push_back(s.top());
                    s.push(i);
                }
            }
        }
    }
    
    s = stack<int>();
    // min_right 
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (s.empty()) {
            min_right.push_back(nums.size());
            s.push(i);
        } else {
            if (nums[s.top()] < nums[i]) {
                min_right.push_back(s.top());
                s.push(i);
            } else {
                while (!s.empty() && nums[s.top()] >= nums[i]) {
                    s.pop();
                }
    
                if (s.empty()) {
                    min_right.push_back(nums.size());
                    s.push(i);
                } else {
                    min_right.push_back(s.top());
                    s.push(i);
                }
            }
        }
    }
    
    reverse(min_right.begin(), min_right.end());     

    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (min_left[i] + 1 <= k && min_right[i] - 1 >= k) {
            ans = max(ans, nums[i] * (min_right[i] - (min_left[i] + 1)));
        }
    }   

    return ans;
}

int main() {
    return 0;
}