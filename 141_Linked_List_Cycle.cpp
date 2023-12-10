#include <iostream>
using namespace std;

typedef ListNode node;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        node * first = head;
        node * second = NULL;
        if (head) {
            second = head->next;
        }

        while (first && second) {
            if (first == second) {
                return true;
            }

            first = first->next;
            second = second->next;
            if (second) {
                second = second->next;
            }
        }

        return false;
    }
};

int main() {
    return 0;
}