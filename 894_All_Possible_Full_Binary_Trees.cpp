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
    vector <vector <node *>> dp;

    Solution() {
        dp = vector <vector <node *>> (22);
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        if (n == 1) {
            vector <node *> ret;
            node * hold = new node(0);
            ret.push_back(hold);
            return ret;
        }

        if (dp[n].size() > 0) {
            return dp[n];
        }

        vector <node *> ret;

        for (int i = 1; i < n - 1; i+=2) {
            // left 
            vector <node *> left = allPossibleFBT(i);
            // right 
            vector <node *> right = allPossibleFBT(n - i - 1);

            for (auto l: left) {
                for (auto r: right) {
                    node * hold = new node(0);
                    hold->left = l;
                    hold->right = r;
                    ret.push_back(hold);
                }
            }
        }         

        dp[n] = ret;

        return ret;
    }
};

int main() {
    return 0;
}