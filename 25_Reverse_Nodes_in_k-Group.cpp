#include <iostream>
#include <vector>
using namespace std;

typedef ListNode node;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        node * temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        node * first = head->next ? head->next->next: NULL;
        node * second = head->next;
        node * third = head;
        node * prev = NULL;
        for (int i = 0; i < len/k; i++) {
            node * hold = third;
            for (int j = 0; j < k - 1; j++) {
                second->next = third;
                third = second;
                second = first;
                first = first ? first->next : NULL;
            }
            

            if (i == 0) {
                head = third;
            } else {
                prev->next = third;
            }

            third = second;
            second = first;
            first = first ? first->next: NULL;


            hold->next = third;
            prev = hold;
        }

        return head;
    }
};

int main() {
    return 0;
}