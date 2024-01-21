#include <iostream>
#include <vector>
using namespace std;

typedef TreeNode node;

class Solution {
public:
    void construct(node * root, vector <int> & cons) {
        if (root) {
            if (root->left == NULL && root->right == NULL) {
                cons.push_back(root->val);
            }

            construct(root->left, cons);
            construct(root->right, cons);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> first, second;
        construct(root1, first);
        construct(root2, second);

        return first == second;
    }
};

int main() {
    return 0;
}   