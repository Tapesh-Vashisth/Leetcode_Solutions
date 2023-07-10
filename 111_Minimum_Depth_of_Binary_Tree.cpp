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
    int minDepth(TreeNode* root) {
        if (root) {
            if (root->left || root->right) {
                // left
                int left = INT32_MAX;
                if (root->left) {
                    left = minDepth(root->left);
                } 
                // right 
                int right = INT32_MAX;
                if (root->right) {
                    right = minDepth(root->right);
                }

                return (min(left, right)) + 1;
            } else {
                return 1;
            }
        } 

        return 0;
    }
};