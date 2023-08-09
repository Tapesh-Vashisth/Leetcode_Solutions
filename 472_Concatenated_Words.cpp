#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    bool end;
    vector <node *> routes;

    node() {
        end = false;
        routes = vector <node *> (26, NULL);
    }       
};

class Trie {
public:
    node * root;

    Trie() {
        root = new node();
    }
    
    void insert(string & word) {
        node * hold = root;
        for (auto it: word) {
            if (hold->routes[it - 'a'] != NULL) {
                hold = hold->routes[it - 'a'];
            } else {
                node * temp = new node();
                hold->routes[it - 'a'] = temp;
                hold = hold->routes[it - 'a'];
            }
        }

        hold->end = true;
    }
    
    bool search(string & word) {
        node * hold = root;
        for (auto it: word) {
            if (hold->routes[it - 'a'] != NULL) {
                hold = hold->routes[it - 'a'];
            } else {
                return false;
            }
        }

        if (hold->end == true) {
            return true;
        }

        return false;
    }
    
    bool startsWith(string & prefix) {
        node * hold = root;
        for (auto it: prefix) {
            if (hold->routes[it - 'a'] == NULL) {
                return false;
            }
            hold = hold->routes[it - 'a'];
        }

        return true;
    }

    bool helper(string & str, vector <node *> store) {
        for (auto it: str) {
            bool decider = false;
            for (int i = 0; i < store.size(); i++) {
                if (store[i] != NULL) {
                    store[i] = store[i]->routes[it - 'a'];
                }

                if (store[i]->end) {
                    decider = true;
                }
            }

            if (decider) {
                store.push_back(root);
            }
        }

        for (auto it: store) {
            if (it && it->end) {
                return true;
            }
        }

        return false;
    }

    bool check(string & str) {
        vector <node *> store = {root};
        return helper(str, store);
    }
};

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    Trie t;

    vector <string> ans;

    for (auto & it: words) {
        if (t.check(it)) {
            ans.push_back(it);
        }

        t.insert(it);
    }

    return ans;
}

int main() {
    return 0;
}