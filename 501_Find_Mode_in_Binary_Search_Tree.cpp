#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

typedef TreeNode node;

class Solution {
public:
    int modeVal = 0;
    vector <int> ans;

    pair <pair <int, int>, pair <int, int>> helper(node * root) {
        if (root) {
            pair <pair <int, int>, pair <int, int>> left = helper(root->left);

            pair <pair <int, int>, pair <int, int>> right = helper(root->right);

            int mn = min(root->val, min(left.first.first, right.first.first));
            int mx = max(root->val, max(left.second.first, right.second.first));
            int minCount = (mn == left.first.first ? left.first.second : 0) + (mn == right.first.first ? right.first.second : 0) + (mn == root->val ? 1: 0);
            int maxCount = (mx == left.second.first ? left.second.second : 0) + (mx == right.second.first ? right.second.second : 0) + (mx == root->val ? 1: 0);


            bool decider = false;
            int counter;
            if (root->val == left.second.first && root->val == right.first.first) {
                counter = 1 + left.second.second + right.first.second;
                decider = true;
            } else if (root->val == left.second.first) {
                counter = 1 + left.second.second;
                decider = true;
            } else if (root->val == right.first.first) {
                counter = 1 + right.first.second;
                decider = true;
            } else {
                if (modeVal <= 1) {
                    modeVal = 1;
                    ans.push_back(root->val);
                }
            }

            if (decider) {
                if (counter > modeVal) {
                    modeVal = counter;
                    ans.clear();
                    ans.push_back(root->val);
                } else if (counter == modeVal) {
                    ans.push_back(root->val);
                }
            }

            return {{mn, minCount}, {mx, maxCount}};
        } 

        return {{INT32_MAX, 0}, {INT32_MIN, 0}};
    }

    vector<int> findMode(TreeNode* root) {
        helper(root);
        return ans;
    }
};