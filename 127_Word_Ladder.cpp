#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class node {
    public:
        vector <node *> points;

        node () {
            points = vector <node *> (26, NULL);
        }
};

class trie {
    public:
        node * root;

        trie () {
            root = new node();
        }

        void insert(node * root, string s, int pos) {
            if (pos == s.size()) {
                return ;
            }

            if (root->points[s[pos] - 'a']) {
                insert(root->points[s[pos] - 'a'], s, pos + 1);
            } else {
                node * hold = new node();
                root->points[s[pos] - 'a'] = hold;
                insert(root->points[s[pos] - 'a'], s, pos + 1);
            }
        }

        void construct(string s, int pos, int diff, unordered_map <string, vector <pair <string, int>>> & graph, node * root, string cons) {
            if (pos > s.size() || diff > 1) {
                return ;
            }

            if (pos == s.size() && diff == 1) {
                graph[s].push_back({cons, 1});
            }

            for (int i = 0; i < root->points.size(); i++) {
                if (root->points[i]) {
                    cons.push_back('a' + i);
                    construct(s, pos + 1, 'a' + i == s[pos] ? diff: diff + 1, graph, root->points[i], cons);
                    cons.pop_back();
                }
            }
        }
};


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    trie t;

    t.insert(t.root, beginWord, 0);
    for (auto it: wordList) {
        t.insert(t.root, it, 0);
    }   

    unordered_map <string, vector <pair <string, int>>> graph;

    t.construct(beginWord, 0, 0, graph, t.root, "");
    for (auto it: wordList) {
        graph[it] = {};
        t.construct(it, 0, 0, graph, t.root, "");
    }   

    
    priority_queue <pair <int, string>, vector<pair <int, string>>, greater<pair <int, string>>> store;
    
    store.push({0, beginWord});
    
    unordered_map <string, int> ans;
    
    for (auto it: wordList) {
        ans[it] = -1;
    }

    ans[endWord] = -1;

    ans[beginWord] = 0;
    
    for (int i = 0; i < wordList.size() && store.size() > 0; i++) {
        pair <int, string> hold = store.top();
        store.pop();
        cout << hold.second << endl;
        for (int j = 0; j < graph[hold.second].size(); j++) {
            if (ans[graph[hold.second][j].first] != -1) {
                if (ans[graph[hold.second][j].first] > hold.first + graph[hold.second][j].second) {
                    store.push({ans[graph[hold.second][j].first], graph[hold.second][j].first});
                }
                
                ans[graph[hold.second][j].first] = min(ans[graph[hold.second][j].first], hold.first + graph[hold.second][j].second);
            } else {
                ans[graph[hold.second][j].first] = hold.first + graph[hold.second][j].second;
                store.push({ans[graph[hold.second][j].first], graph[hold.second][j].first});
            }
            
        }    
    }

    if (ans[endWord] == -1) {
        return 0;
    }

    return ans[endWord] + 1;
}

int main(){
    return 0;
}