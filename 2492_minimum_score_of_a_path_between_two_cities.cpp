#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// int ans;
// unordered_map <pair <int, int>, bool> visited;
// void dfs(int root, vector <vector <pair <int, int>>>& graph) {
//     for (auto it: graph[root]) {
//         if (visited[{it.first, root}] == false) {
//             visited[{it.first, root}] = true;
//             visited[{root, it.first}] = true;
//             ans = min(ans, it.second);
//             dfs(it.first, graph);
//         }
//     }
// } 


// int minScore(int n, vector<vector<int>>& roads) {
//     vector <vector <pair <int, int>>> graph(n);

//     for (auto it: roads) {
//         graph[it[0] - 1].push_back({it[1] - 1, it[2]});
//     }
    
//     ans = INT32_MAX;
//     dfs(0, graph);

//     return ans;
// }

class DSU {
    private:
        vector <int> parent;

    public:
        DSU(int n) {
            parent.resize(n);
            for(int i = 0; i<n; i++) parent[i] = i;
        }

        int find(int ele) {
            if (parent[ele] == ele) {
                return ele;
            } 

            int par = find(parent[ele]);

            parent[ele] = par;

            return par;
        }


        void U(int a, int b) {
            int p1 = find(a);
            int p2 = find(b);

            parent[a] = p1;
            parent[b] = p2;
            
            if (p1 != p2) {
                parent[p1] = p2;
            }
        }

        void print() {
            for (int i = 0; i < parent.size(); i++) {
                cout << i << " " << parent[i] << endl;
            }
        }
};

int minScore(int n, vector<vector<int>>& roads) {
    int ans = INT32_MAX;
    DSU hold(n);

    for (auto it: roads) {
        if (hold.find(1) == hold.find(it[0]) || hold.find(1) == hold.find(it[1])) {
            ans = min(ans, it[2]);
        }
        hold.U(it[0], it[1]);
    }

    return ans;
}

int main() {
    return 0;
}