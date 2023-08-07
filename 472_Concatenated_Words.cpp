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

    bool contains(string & check) {
        node * hold = root;
        int counter = 0;
        for (auto it: check) {
            if (hold->routes[it - 'a'] == NULL) {
                return false;
            }

            hold = hold->routes[it - 'a'];
            if (hold->end == true) {
                return true;
            }

            counter++;
        }

        return false;
    }
};

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    Trie t;

    for (auto & it: words) {
        t.insert(it);
    }

    vector <string> ans;

    for (auto & it: words) {
        if (t.contains(it)) {
            ans.push_back(it);
        }
    }

    return ans;
}

int main() {
    return 0;
}