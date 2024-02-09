#include <iostream>
#include <vector>
using namespace std;

typedef TreeNode node;

class Solution {
public:
    int helper(node * root, int decider){
        if (root){
            if (root->left == NULL && root->right == NULL){
                decider = decider ^ (1 << (root->val - 1)); 
                int counter = 0;
                while (decider){
                    counter += (decider&1);
                    decider =  decider >> 1;
                }
                
                if (counter == 0 || counter == 1){
                    return true;
                }else{
                    return false;
                }
            }else{
                int left = helper(root->left, (decider ^ (1 << (root->val - 1))));
                int right = helper(root->right, (decider ^ (1 << (root->val - 1))));
                return left + right;
            }    
        }else{
            return 0;
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = helper(root, 0);
        return ans;
    }
};

int main() {
    return 0;
}