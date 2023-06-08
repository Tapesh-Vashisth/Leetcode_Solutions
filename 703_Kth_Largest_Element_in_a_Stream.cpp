#include <iostream>
#include <set>
using namespace std;

class node {
    public:
        int val;
        node * left;
        node * right;

        node(int value) {
            left = NULL;
            right = NULL;
            val = value;
        }
};

class tree {
    public:
        node * root;
    
        tree () {
            root = NULL;
        }

        node * insertHelper(node * root, int val) {
            if (root) {
                if (val > root->val) {
                    root->right = insertHelper(root->right, val);
                } else {
                    root->left = insertHelper(root->left, val);
                }

                return root;
            } else {
                node * n = new node(val);
                return n;    
            }
        }

        void insert(int val) {
            insertHelper(root, val);
        }

        int kthHelper(node * root, int k, int & ans) {
            if (root) {
                int right = kthHelper(root->right, k, ans);

                if (right + 1 == k) {
                    ans = root->val;
                }
                
                int left = 0;
                if (right + 1 <= k) {
                    left = kthHelper(root->left, k, ans);
                }

                return right + left + 1;
            } else {
                return 0;
            }
        }

        int kth(int k) {
            int ans = 0;
            kthHelper(root, k, ans);

            return ans;
        }
};


int main() {
    set <int> store;

    return 0;
}