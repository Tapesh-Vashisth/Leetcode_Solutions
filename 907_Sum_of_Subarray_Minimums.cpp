#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int sumSubarrayMins(vector<int>& store) {
    stack <int> s;
    vector <int> min_left;
    vector <int> min_right;
    
    int n = store.size();

    s = stack<int>();

    // min_left 
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            min_left.push_back(-1);
            s.push(i);
        } else {
            if (store[s.top()] <= store[i]) {
                min_left.push_back(s.top());
                s.push(i);
            } else {
                while (!s.empty() && store[s.top()] > store[i]) {
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
    for (int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            min_right.push_back(store.size());
            s.push(i);
        } else {
            if (store[s.top()] < store[i]) {
                min_right.push_back(s.top());
                s.push(i);
            } else {
                while (!s.empty() && store[s.top()] >= store[i]) {
                    s.pop();
                }
    
                if (s.empty()) {
                    min_right.push_back(store.size());
                    s.push(i);
                } else {
                    min_right.push_back(s.top());
                    s.push(i);
                }
            }
        }
    }
    
    reverse(min_right.begin(), min_right.end());   

    long long mod = 1e9 + 7;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans = (ans + (store[i] * (((i - min_left[i]) * (min_right[i] - i)) % mod)) % mod) % mod;
    }

    return ans;     
}

int main() {
    return 0;
}