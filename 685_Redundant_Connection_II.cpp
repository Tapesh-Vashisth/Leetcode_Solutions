#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    vector <vector <int>> graph(edges.size());
    vector <vector <int>> reverseGraph(edges.size());

    vector <int> inorder(edges.size(), 0);
    vector <int> outorder(edges.size(), 0);

    for (auto & it: edges) {
        inorder[it[1] - 1]++;
        outorder[it[0] - 1]++;
        graph[it[0] - 1].push_back(it[1] - 1);
        reverseGraph[it[1] - 1].push_back(it[0] - 1);
    }   

    vector <int> ans;

    queue <int> store;

    bool check = true;
    int hold = 0;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == 0) {
            store.push(i);
            check = false;
        } else if (inorder[i] == 2) {
            hold = i;
        }
    }

    if (check) {
        queue <int> store2;
        vector <bool> hash(edges.size(), true);

        for (int i = 0; i < outorder.size(); i++) {
            if (outorder[i] == 0) {
                store2.push(i);
            }
        }

        while (!store2.empty()) {
            int hold = store2.front();
            hash[hold] = false;
            store2.pop();

            for (auto it: reverseGraph[hold]) {
                outorder[it]--;

                if (outorder[it] == 0) {
                    store2.push(it);
                }
            }
        }

        for (int j = edges.size() - 1; j >= 0; j--) {
            if (hash[edges[j][0] - 1] && hash[edges[j][1] - 1]) {
                ans = edges[j];
                break;
            }
        }
    } else {
        vector <int> inorderHold = inorder;

        vector <bool> hash(edges.size(), true);

        while (!store.empty()) {
            int hold = store.front();
            hash[hold] = false;
            store.pop();

            for (auto it: graph[hold]) {
                inorderHold[it]--;

                if (inorderHold[it] == 0) {
                    store.push(it);
                }
            }
        }

        bool secondCheck = false;
        for (auto it: inorderHold) {
            if (it > 0) {
                secondCheck = true;
                break;
            }   
        }

        if (secondCheck) {
            for (int j = edges.size() - 1; j >= 0; j--) {
                if (edges[j][1] == hold + 1 && hash[edges[j][0] - 1]) {
                    ans = edges[j];
                    break;
                }
            }
        } else {
            for (int j = edges.size() - 1; j >= 0; j--) {
                if (edges[j][1] == hold + 1) {
                    ans = edges[j];
                    break;
                }
            }
        }
    }


    return ans;
}

int main() {
    return 0;
}