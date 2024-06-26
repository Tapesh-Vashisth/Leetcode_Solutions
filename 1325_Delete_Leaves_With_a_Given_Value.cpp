#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (root)
        {
            TreeNode *left = removeLeafNodes(root->left, target);
            TreeNode *right = removeLeafNodes(root->right, target);

            root->left = left;
            root->right = right;

            if (left == NULL && right == NULL)
            {
                if (root->val == target)
                {
                    return NULL;
                }
                else
                {
                    return root;
                }
            }
            else
            {
                return root;
            }
        }
        else
        {
            return NULL;
        }
    }
};