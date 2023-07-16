#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    class node {
    public:
        bool end;
        node * routes[26];

        node() {
            end = false;
            for (int i = 0; i < 26; i++) {
                routes[i] = NULL;
            }
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

        int helper(string & s, int startPoint) {
            node * hold = root;
            int index = startPoint;
            while (index < s.size() && hold->end == false) {
                if (hold->routes[s[index] - 'a'] == NULL) {
                    return s.size() - 1;
                } 

                hold = hold->routes[s[index] - 'a'];
                
                if (hold->end == true) {
                    return index - 1;
                }
                
                index++;
            }

            if (hold->end == true) {
                return s.size() - 2;
            } else {
                return s.size() - 1;
            }
        }

        ~Trie() {
            delete root;
        }
    };

    int longestValidSubstring(string word, vector<string>& forbidden) {
        Trie * t = new Trie();
        for (auto & it: forbidden) {
            t->insert(it);
        }        

        vector <int> cons;
        for (int i = 0; i < word.size(); i++) {
            int hold = t->helper(word, i);
            cons.push_back(hold);
        }

        
        vector <int> hash(word.size() + 1, -1);
        
        int mx = 0;
        queue <int> keep;
        for (int i = 0; i < cons.size(); i++) {
            if (cons[i] < i) {
                while (!keep.empty()) {
                    keep.pop();
                }
            } else if (cons[i] == i) {
                int hold = keep.size() + 1;
                mx = max(hold, mx);

                while (!keep.empty()) {
                    keep.pop();
                }
            } else {
                hash[cons[i]] = max(hash[cons[i]], i);
                keep.push(i);
                
                int hold = keep.size();
                mx = max(mx, hold);

                if (hash[i] != -1) {
                    while (!keep.empty() && keep.front() <= hash[i]) {
                        keep.pop();
                    }
                }
            }
        }
        
        return mx;
    }
};