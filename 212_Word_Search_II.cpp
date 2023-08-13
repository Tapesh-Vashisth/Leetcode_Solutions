#include <iostream>
#include <vector>
#include <set>
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
    
    void insert(string word) {
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
    
    bool search(string word) {
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

    void helper(vector <vector <char>> & board, int x, int y, node * current, set <string> & ans, string & construct, vector <vector <bool>> & visited) {
        if (visited[x][y]) {
            visited[x][y] = false;

            if (current->end) {
                ans.insert(construct);
            }

            // up 
            if (x - 1 >= 0 && current->routes[board[x - 1][y] - 'a'] != NULL) {
                construct.push_back(board[x - 1][y]);
                helper(board, x - 1, y, current->routes[board[x - 1][y] - 'a'], ans, construct, visited);
                construct.pop_back();
            }


            // down 
            if (x + 1 < board.size() && current->routes[board[x + 1][y] - 'a'] != NULL) {
                construct.push_back(board[x + 1][y]);
                helper(board, x + 1, y, current->routes[board[x + 1][y] - 'a'], ans, construct, visited);
                construct.pop_back();
            }


            // left 
            if (y - 1 >= 0 && current->routes[board[x][y - 1] - 'a'] != NULL) {
                construct.push_back(board[x][y - 1]);
                helper(board, x, y - 1, current->routes[board[x][y - 1] - 'a'], ans, construct, visited);
                construct.pop_back();
            }


            // right 
            if (y + 1 < board[0].size() && current->routes[board[x][y + 1] - 'a'] != NULL) {
                construct.push_back(board[x][y + 1]);
                helper(board, x, y + 1, current->routes[board[x][y + 1] - 'a'], ans, construct, visited);
                construct.pop_back();
            }


            visited[x][y] = true;
        }
    } 
};

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie t;
    for (auto &it: words) {
        t.insert(it);
    }

    set <string> ans;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (t.root->routes[board[i][j] - 'a'] != NULL) {
                vector <vector <bool>> visited (board.size(), vector <bool> (board[0].size(), true));
                string temp;
                temp.push_back(board[i][j]);
                t.helper(board, i, j, t.root->routes[board[i][j] - 'a'], ans, temp, visited);
            }
        }
    }

    vector <string> realans;
    for (auto it: ans) {
        realans.push_back(it);
    }

    return realans;
}


int main() {
    return 0;
}