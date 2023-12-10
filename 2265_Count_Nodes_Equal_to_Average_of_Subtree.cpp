#include <iostream>
#include <vector>
using namespace std;

typedef TreeNode node;

class Solution {
public:
    int ans;

    pair <int, int> helper(node * root) {
        if (root) {
            pair <int, int> left = helper(root->left);
            pair <int, int> right = helper(root->right);

            int total = left.first + right.first + root->val;
            int counter = left.second + right.second + 1;
            
            if (root->val == total/counter) {
                ans++;
            }

            return {total, counter};
        } else {
            return {0, 0};
        }
    }

    int averageOfSubtree(node * root) {
        ans = 0;

        helper(root);

        return ans;
    }
};

int main() {
    return 0;
}