#include <iostream>
#include <vector>
using namespace std;

vector <vector <vector <int>>> dp;

int helper(vector <int> & boxes, int left, int right, int k) {
    if (left > right) {
        return 0;
    } else if (left == right) {
        return (k + 1) * (k + 1);
    }

    if (dp[left][right][k] != -1) {
        return dp[left][right][k];
    }

    int mx = ((k + 1) * (k + 1)) + helper(boxes, left + 1, right, 0);

    for (int i = left + 1; i <= right; i++) {
        if (boxes[i] == boxes[left]) {
            int hold = helper(boxes, left + 1, i - 1, 0) + helper(boxes, i, right, k + 1);
            mx = max(mx, hold);
        }
    }


    dp[left][right][k] = mx;

    return mx;
}

int removeBoxes(vector<int>& boxes) {
    dp = vector <vector <vector <int>>> (boxes.size(), vector <vector<int>> (boxes.size(), vector<int> (boxes.size() + 1, -1))); 
    return helper(boxes, 0, boxes.size() - 1, 0);
}

int main() {
    return 0;
}