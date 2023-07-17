#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <int> store1;
        stack <int> store2;

        node * temp1 = l1;
        while (temp1 != NULL) {
            store1.push(temp1->val);
            temp1 = temp1->next;
        } 

        node * temp2 = l2;
        while (temp2 != NULL) {
            store2.push(temp2->val);
            temp2 = temp2->next;
        }

        node * ans = NULL;
        int carry = 0;
        while (!store1.empty() || !store2.empty()) {
            if (store1.empty()) {
                int val = store2.top() + carry;
                carry = val / 10;
                int rem = val % 10;
                
                node * n = new node(rem, ans);
                ans = n;
                store2.pop();
            } else if (store2.empty()) {
                int val = store1.top() + carry;
                carry = val / 10;
                int rem = val % 10;
                
                node * n = new node(rem, ans);
                ans = n;
                store1.pop();
            } else {
                int val = store1.top() + store2.top() + carry;
                carry = val / 10;
                int rem = val % 10;
                
                if (ans == NULL) {
                    ans = new node(rem);
                } else {
                    node * n = new node(rem, ans);
                    ans = n;
                }
                store1.pop();
                store2.pop();
            }
        }

        if (carry > 0) {
            int rem = carry;
            
            node * n = new node(rem, ans);
            ans = n;
            store1.pop();
        }

        return ans;
    }
};

int main() {
    return 0;
}