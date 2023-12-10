#include <iostream>
#include <vector>
#include <map>
using namespace std;

class node{
    public:
        node * next;
        int data;
        string s;
        node * prev;

        node() {
            next = NULL;
            prev = NULL;
            data = 0;
            s = "";
        }

        node(int val, string str) {
            next = NULL;
            prev = NULL;
            data = val;
            s = str;
        }
};

class double_linked_list{
    public:
        int len;
        node * first;
        node * last;

        double_linked_list() {
            first = NULL;
            last = NULL;
            len = 0;
        }

        int getlength(){
            return len;
        }

        node * insertFirst(int val, string s) {
            node * n = new node(val, s);
            n->next = first;
            if (first) {
                first->prev = n;
            }
            first = n;

            if (len == 0) {
                last = n;
            }

            len++;

            return n;
        }

        void increment(node * root) {
            int newVal = root->data + 1;
            root->data = newVal;
            node * temp = root->next;

            int counter = 0;
            while (temp != NULL && temp->data < newVal) {
                temp = temp->next;
                counter++;
            } 

            if (root == first) {
                if (counter == 0) {
                    ;
                } else {
                    first = root->next;
                    first->prev = NULL;
                    if (temp == NULL) {
                        root->next = last->next;
                        last->next = root;
                        root->prev = last;
                        last = root;
                    } else {
                        temp->prev->next = root;
                        root->prev = temp->prev;
                        root->next = temp;
                        temp->prev = root;
                    }
                }
            } else {
                if (counter) { 
                    root->prev->next = root->next;
                    root->next->prev = root->prev;
                    root->next = temp;
                    if (temp == NULL) {
                        cout << "hm" << endl;
                        last->next = root;
                        root->prev = last; 
                        last = root;
                    } else {
                        root->prev = temp->prev;
                        temp->prev = root;
                    }
                }
            }
        }

        bool decrement(node * root) {
            int newVal = root->data - 1;
            root->data = newVal;
            if (newVal == 0) {
                if (root == first) {
                    first = root->next;
                    if (first == NULL) {
                        last = NULL;
                    } else {
                        first->prev = NULL;
                    }
                } else if (root == last) {
                    last = root->prev;
                    if (last == NULL) {
                        first = NULL;
                    } else {
                        last->next = NULL;
                    }
                } else {
                    root->prev->next = root->next;
                    if (root->next) {
                        root->next->prev = root->prev;
                    }
                }
                len--;

                return true;
            } else {
                node * temp = root->prev;
                int counter = 0;
                while (temp != NULL && temp->data > newVal) {
                    temp = temp->prev;
                    counter++;
                } 

                if (root == last) {
                    if (counter == 0) {
                        ;
                    } else {
                        last = root->prev;
                        last->next = NULL;
                        if (temp == NULL) {
                            root->prev = first->prev;
                            first->prev = root;
                            root->next = first;
                            first = root;
                        } else {
                            temp->next->prev = root;
                            root->next = temp->next;
                            root->prev = temp;
                            temp->next = root;
                        }
                    }
                } else {
                    if (counter) { 
                        root->next->prev = root->prev;
                        root->prev->next = root->next;
                        root->prev = temp;
                        if (temp == NULL) {
                            first->prev = root;
                            root->next = first; 
                            first = root;
                        } else {
                            root->next = temp->next;
                            temp->next = root;
                        }
                    }
                }
            }

            return false;
        }

        void fdisplay(){
            node * p = first;
            cout << len << endl;
            while (p != NULL){
                cout << p->data << " " << p->s << endl;
                p = p->next;
            }
            cout << endl;
        }

        void bdisplay(){
            node * p = last;
            cout << len << endl;
            while (p != NULL){
                cout << p->data << " " << p->s << endl;
                p = p->prev;
            }
            cout << endl;
        }
};

class AllOne {
    private:
        double_linked_list list;
        map <string, node *> mapping;

    public:
        AllOne() {
            ;
        }
        
        void inc(string key) {
            if (mapping[key] == NULL) {
                mapping[key] = list.insertFirst(1, key);
            } else {
                node * hold = mapping[key];
                list.increment(hold);
            } 
        }
        
        void dec(string key) {  
            if (list.decrement(mapping[key])) {
                mapping[key] = NULL;
            } else {
                ;
            }
        }
        
        string getMaxKey() {
            if (list.getlength() == 0) {
                return "";
            }

            return list.last->s;
        }
        
        string getMinKey() {
            if (list.getlength() == 0) {
                return "";
            }

            return list.first->s;
        }
};

int main() {
    return 0;
}