#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack <int> s;
    // next smallest from left 
    vector <int> left;
    for (int i = 0; i < heights.size(); i++) {
        if (s.empty()) {
            left.push_back(-1);
            s.push(i);
        } else {
            if (heights[s.top()] < heights[i]) {
                left.push_back(s.top());
                s.push(i);
            } else {
                while (!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }

                if (s.empty()) {
                    left.push_back(-1);
                    s.push(i);
                } else {
                    left.push_back(s.top());
                    s.push(i);
                }
            }
        }
    }

    for (int i = 0; i < left.size(); i++) {
        cout << left[i] << " "; 
    }

    cout << endl;


    s = stack <int> (); 
    // next smallest from right 
    vector <int> right;
    for (int i = heights.size() - 1; i >= 0; i--) {
        if (s.empty()) {
            right.push_back(heights.size());
            s.push(i);
        } else {
            if (heights[s.top()] < heights[i]) {
                right.push_back(s.top());
                s.push(i);
            } else {
                while (!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }

                if (s.empty()) {
                    right.push_back(heights.size());
                    s.push(i);
                } else {
                    right.push_back(s.top());
                    s.push(i);
                }
            }
        }
    }

    for (int i = 0; i < right.size(); i++) {
        cout << right[i] << " "; 
    }

    cout << endl;

    int ans = 0;

    for (int i = 0; i < left.size(); i++) {
        ans = max(ans, (right[heights.size() - i - 1] - left[i] - 1) * heights[i]); 
        cout << ans << endl;
    }

    return ans;
}

int main() {
    vector <int> check = {2,1,5,6,2,3};
    largestRectangleArea(check);
    return 0;
}