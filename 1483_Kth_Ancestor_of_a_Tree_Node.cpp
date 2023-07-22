#include <iostream>
#include <vector>
using namespace std;

class TreeAncestor {
public:
    vector <vector <int>> table;
    vector <vector <int>> tree;


    void dfs(int node) {
        for (int i = 1; i < table[node].size(); i++) {
            table[node][i] = table[node][i - 1] == -1 ? -1 : table[table[node][i - 1]][i - 1];
        }

        for (auto it: tree[node]) {
            dfs(it);
        }
    }

    TreeAncestor(int n, vector<int>& parent) {
        int m = n;
        int log = 0;
        while (m) {
            log++;
            m = m >> 1;
        }
        log++;
        table = vector <vector <int>> (n, vector <int> (log, 0));
        tree = vector <vector <int>> (n);

        for (int i = 0; i < parent.size(); i++) {
            table[i][0] = parent[i];
            if (parent[i] != -1) {
                tree[parent[i]].push_back(i);
            }
        }


        dfs(0);
    }
    
    int getKthAncestor(int node, int k) {
        int ans = node;
        int counter = 0;
        while (k) {
            if (k & 1) {
                ans = table[ans][counter];
            }

            if (ans == -1) {
                return ans;
            }

            counter++;
            k = k >> 1;
        }

        return ans;
    }
};

int main() {
    return 0;
}