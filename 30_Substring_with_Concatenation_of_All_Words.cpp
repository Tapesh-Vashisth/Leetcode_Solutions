#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class node {
public:
    int end;
    vector <node *> routes;

    node() {
        end = -1;
        routes = vector <node *> (26, NULL);
    }       
};

class Trie {
public:
    node * root;

    Trie() {
        root = new node();
    }
    
    void insert(string & word, int index) {
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

        hold->end = index;
    }
    
    int search(string & word, int start, int end) {
        node * hold = root;
        for (int i = start; i < end; i++) {
            if (hold->routes[word[i] - 'a'] != NULL) {
                hold = hold->routes[word[i] - 'a'];
            } else {
                return false;
            }
        }

        return hold->end;
    }
    
    bool startsWith(string prefix) {
        node * hold = root;
        for (auto it: prefix) {
            if (hold->routes[it - 'a'] == NULL) {
                return false;
            }
            hold = hold->routes[it - 'a'];
        }

        return true;
    }
};

vector<int> findSubstring(string s, vector<string>& words) {
    Trie t;
    set <string> store;
    int n = words[0].size();

    for (auto & it: words) {
        store.insert(it);
    }

    int index = 0;
    for (auto it: store) {
        cout << it << " ";
        t.insert(it, index);
        index++;
    }
    cout << endl;

    vector <int> hash(store.size(), 0);
    for (auto & it: words) {
        int hold = t.search(it, 0, it.size());
        hash[hold]++;
    }


    vector <int> check(s.size(), -1);

    for (int i = 0; i < s.size(); i++) {
        check[i] = t.search(s, i, i + n);
    }

    for (auto it: check) {
        cout << it << " ";
    }
    cout << endl;

    vector <int> ans;

    return ans;
}

int main() {
    return 0;
}