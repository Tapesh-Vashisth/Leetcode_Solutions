#include <iostream>
using namespace std;


typedef ListNode node;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int counter = 0;
        node * first = head ? head->next: NULL;
        node * second = head;
        node * third = head;
        while (first != NULL) {
            if (counter % 2 == 0){
                second->next = first->next;
                first->next = second;

                if (counter == 0) {
                    head = first;
                } else {
                    third->next = first;
                }
                
                node * temp = first;
                first = second;
                second = temp;
            }

            third = second;
            second = first;
            first = first->next;
            counter++;
        }

        return head;
    }
};

int main() {
    return 0;
}