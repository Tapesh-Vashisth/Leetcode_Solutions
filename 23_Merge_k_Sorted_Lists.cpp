#include <iostream>
#include <vector>
using namespace std;

typedef ListNode node;

class Solution {
public:
    node * helper(vector <ListNode *> & lists, int low, int high) {
        if (low >= high) {
            return lists[low];
        }

        int mid = (low + high)/2;

        node * first = helper(lists, low, mid);
        node * second = helper(lists, mid + 1, high);

        node * hold = NULL;
        node * root = hold;
        node * firstPointer = first;
        node * secondPointer = second;

        int counter = 0;
        while (firstPointer && secondPointer) {
            if (firstPointer->val < secondPointer->val) {
                if (counter == 0) {
                    hold = new node(firstPointer->val);
                    root = hold;
                } else {
                    node * temp = new node(firstPointer->val);
                    hold->next = temp;
                    hold = temp;
                }

                firstPointer = firstPointer->next;
            } else {
                if (counter == 0) {
                    hold = new node(secondPointer->val);
                    root = hold;
                } else {
                    node * temp = new node(secondPointer->val);
                    hold->next = temp;
                    hold = temp;
                }

                secondPointer = secondPointer->next;
            }

            counter++;
        }

        while (firstPointer) {
            if (counter == 0) {
                hold = new node(firstPointer->val);
                root = hold;
            } else {
                node * temp = new node(firstPointer->val);
                hold->next = temp;
                hold = temp;
            }
            firstPointer = firstPointer->next;
            counter++;
        }

        while (secondPointer) {
            if (counter == 0) {
                hold = new node(secondPointer->val);
                root = hold;
            } else {
                node * temp = new node(secondPointer->val);
                hold->next = temp;
                hold = temp;
            }
            secondPointer = secondPointer->next;
            counter++;
        }

        return root;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }

        return helper(lists, 0, lists.size() - 1);
    }
};

int main() {
    return 0;
}