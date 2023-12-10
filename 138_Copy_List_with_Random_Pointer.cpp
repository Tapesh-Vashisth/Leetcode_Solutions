#include <iostream>
#include <vector>
#include <map>
using namespace std;

Node* copyRandomList(Node* head) {
    Node * construct = NULL;
    Node * constructTemp = NULL;

    int len = 0;
    map <Node *, int> mapping;
    vector <Node *> hash;
    Node * temp = NULL;
    if (head) {
        construct = new Node(head->val);
        constructTemp = construct;
        mapping[head] = len;
        hash.push_back(construct);
        temp = head->next;
        len++;
    }


    while (temp) {
        Node * n = new Node(temp->val);
        mapping[temp] = len;
        hash.push_back(n);
        constructTemp->next = n;

        constructTemp = constructTemp->next;
        temp = temp->next;
        len++;
    }

    temp = head;
    constructTemp = construct;
    while (temp) {
        Node * hold = temp->random;
        if (hold) {
            constructTemp->random = hash[mapping[hold]];
        }

        temp = temp->next;
        constructTemp = constructTemp->next;
    }

    return construct;
}

int main() {
    return 0;
}