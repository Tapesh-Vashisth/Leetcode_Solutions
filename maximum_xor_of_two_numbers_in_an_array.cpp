#include <iostream>
#include <vector>
using namespace std;

class node {
    public:
        int val;
        vector <node *> childs;

        node (int val) {
            this->val = val;
        }

        node (int val, int size) {
            this->val = val;
            this->childs = vector <node *> (size, NULL);
        }

        void setChildSize(int size) {
            childs = vector <node *> (size, NULL);
        }
};

class trie {
    public:
        node * root;
        int branches;

        trie (int branches) {
            root = new node(-1, branches);
            this->branches = branches;
        }

        void insert(int val) {
            int bitTraverse = 1 << 30;
            node * hold = root;
            int counter = 0;
            while (bitTraverse) {
                int bit = val & bitTraverse ? 1: 0;
                if (hold->childs[bit] == NULL) {
                    node * temp = new node(bit, branches);
                    hold->childs[bit] = temp;
                    hold = temp;
                } else {
                    hold = hold->childs[bit];
                }

                bitTraverse = bitTraverse >> 1;
            }
        }

        void print(node * hold, int level) {
            if (hold) {
                cout << "level: " << level << ", value: " << hold->val << ": ";

                for (int i = 0; i < branches; i++) {
                    if (hold->childs[i]) {
                        cout << hold->childs[i]->val << " ";
                    }
                }

                cout << endl;

                for (int i = 0; i < branches; i++) {
                    print(hold->childs[i], level + 1);
                }
            }        
        }

};

int ans = 0;

void findMax(node * first, node * second, int current, int bitmask) {
    if (first && second) { 
        if (first->childs[0] && first->childs[1] && second->childs[0] && second->childs[1]) {
            current = current | bitmask;
            findMax(first->childs[0], second->childs[1], current, bitmask >> 1);
            findMax(first->childs[1], second->childs[0], current, bitmask >> 1);
        } else if (first->childs[1] && second->childs[0]) {
            current = current | bitmask;
            first = first->childs[1];
            second = second->childs[0];
            findMax(first, second, current, bitmask >> 1);
        } else if (first->childs[0] && second->childs[1]) {
            current = current | bitmask;
            first = first->childs[0];
            second = second->childs[1];
            findMax(first, second, current, bitmask >> 1);
        } else if (first->childs[0] && second->childs[0]) {
            first = first->childs[0];
            second = second->childs[0];
            findMax(first, second, current, bitmask >> 1);
        } else {
            first = first->childs[1];
            second = second->childs[1];
            findMax(first, second, current, bitmask >> 1);
        }

        ans = max(ans, current);
    }
}

int findMaximumXOR(vector<int>& nums) {
    trie store(2);
    for (auto it: nums) {
        store.insert(it);
    }        

    ans = 0;
    node * first = store.root;
    node * second = store.root;
    int bitmask = 1 << 30;
    findMax(first, second, 0, bitmask);
    return ans;
}

int main() {
    return 0;
}