#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef TreeNode node;

class Solution {
public:
    long long ans = INT32_MAX;

    pair <long long, long long> helper(node * root) {
        if (root) {
            pair <long long, long long> left = helper(root->left);
            pair <long long, long long> right = helper(root->right);

            ans = min(ans, abs(left.first - root->val));
            ans = min(ans, abs(right.second - root->val));

            return {max((long long)root->val, right.first), min((long long)root->val, left.second)};
        }

        return {INT32_MIN, INT32_MAX};
    }

    int getMinimumDifference(TreeNode* root) {
        helper(root);

        return ans;
    }
};

int main() {
    return 0;
}