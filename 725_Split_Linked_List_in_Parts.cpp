#include <iostream>
#include <vector>
using namespace std;

typedef ListNode node;
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len = 0;
    node * temp = head;
    while (temp) {
        len++;
        temp = temp->next;
    }

    vector <node *> ans;

    if (k == 1) {
        ans.push_back(head);
        return ans;
    }

    if (k >= len) {
        temp = head;
        int index = 0;
        while (temp) {
            node * n = new node(temp->val);
            ans.push_back(n);
            temp = temp->next;
            index++;
        }

        while (index < k) {
            ans.push_back(NULL);
            index++;
        } 
    } else {
        int big = (len + k - 1)/k;
        int hold = len;
        temp = head;
        while (hold % (big - 1) != 0 || (hold % (big - 1) == 0 && (hold/(big - 1) > k - ans.size()))) {
            int keep = big - 1;

            node * insert = new node(temp->val);
            node * temp2 = insert;
            temp = temp->next;
            while (keep) {
                node * n = new node(temp->val);
                temp2->next = n;
                temp2 = temp2->next;
                temp = temp->next;
                keep--;
            }

            ans.push_back(insert);
            hold -= big;
        }

        while (hold) {
            int keep = big - 2;

            node * insert = new node(temp->val);
            node * temp2 = insert;
            temp = temp->next;
            while (keep) {
                node * n = new node(temp->val);
                temp2->next = n;
                temp2 = temp2->next;
                temp = temp->next;
                keep--;
            }

            ans.push_back(insert);
            hold -= big - 1;
        }


    }

    return ans;
}

int main() {
    return 0;
}