typedef ListNode node;

class Solution {
public:
    int helper(node * root, int & back, vector <int> & store) {
        if (root) {
            store.push_back(root->val);
            int hold = helper(root->next, back, store);
            back++;
            
            if (back - 1 == store.size() - back) {
                return hold;
            }

            int temp = store[back - 1] + store[store.size() - back];

            return max(hold, temp);
        } else {
            return 0;
        }
    }

    int pairSum(ListNode* head) {
        int back = 0;
        vector <int> store;
        return helper(head, back, store);
    }
};