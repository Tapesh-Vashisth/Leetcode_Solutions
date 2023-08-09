#include <iostream>
#include <vector>
using namespace std;

int helper(vector <pair <int, int>> & boxes, int left, int right) {
    if (left > right) {
        return 0;
    } else if (left == right) {
        return boxes[left].second * boxes[left].second;
    }

    int ret = INT32_MIN;
    for (int i = left + 1; i <= right; i++) {
        if (boxes[i].first == boxes[left].first) {
            int left = helper(boxes, left + 1, i - 1);

            boxes[i].second += boxes[left].second;
            int right = helper(boxes, i, right);
            boxes[i].second -= boxes[left].second;

            ret = max(ret, left + right);
        }
    }

    return ret;
}

int removeBoxes(vector<int>& boxes) {
    vector <pair <int, int>> updated;
    for (auto it: boxes) {
        updated.push_back({it, 1});
    }

    int ans = helper(updated, 0, boxes.size() - 1);

    return ans;
}

int main() {
    return 0;
}