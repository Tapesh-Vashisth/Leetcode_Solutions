#include <iostream>
using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right) {
    node * temp = head;
    node * prev = NULL;
    
    int index = 1;
    while (index < left) {
        index++;
        prev = temp;
        temp = temp->next;
    }

    node * first = temp->next;
    node * second = temp;

    while (index < right) {
        node * temp = first->next;
        first->next = second;

        second = first;
        first = temp;
        index++;
    }

    if (prev) {
        prev->next = second;
        temp->next = first;
    } else {
        head = second;
        temp->next = first;
    }

    return head;
}

int main() {
    return 0;
}