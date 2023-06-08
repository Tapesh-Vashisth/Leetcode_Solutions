#include <iostream>
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
    vector <node *> helper(int start, int end) {
        if (start > end) {
            vector <node *> ret = {NULL};
            return ret;
        }

        vector <node *> ret;
        for (int i = start; i <= end; i++) {
            vector <node *> left = helper(start, i - 1);
            vector <node *> right = helper(i + 1, end);

            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    node * hold = new node(i);
                    hold->left = left[j];
                    hold->right = right[k];
                    ret.push_back(hold);
                }
            }

        }

        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);      
    }
};

int main() {
    return 0;
}