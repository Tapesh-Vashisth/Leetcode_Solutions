/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef ListNode node;

class Solution {
public:
    node * helper(node * root, int & front, int & back, int & k) {
        if (root) {
            front++;
            node * ret = helper(root->next, front, back, k);
            front--;
            back++;

            if (front == k || back == k) {
                if (ret) {
                    int val = root->val;
                    root->val = ret->val;
                    ret->val = val;
                    return ret;
                } else {
                    return root;
                }
            } 

            return ret;
        } else {
            return NULL;
        }
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int front = 1;
        int back = 0;
        helper(head, front, back, k);

        return head;
    }
};