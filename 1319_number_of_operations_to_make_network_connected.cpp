#include <iostream>
#include <vector>
using namespace std;

// void detector(int root, int prev, vector <vector <int>> & graph, vector <bool>& mainVisited, vector <bool> & visited, int & useless) {
//     if (visited[root] == false) {
//         mainVisited[root] = true;
//         visited[root] = true;
//         for (int i = 0; i < graph[root].size(); i++) {
//             if (graph[root][i] != prev) {
//                 detector(graph[root][i], root, graph, mainVisited, visited, useless);
//             }
//         }
//     } else {
//         useless++;
//     }
// }

// int makeConnected(int n, vector<vector<int>>& connections) {
//     vector <vector <int>> graph (n);
//     for (auto it: connections) {
//         graph[it[0]].push_back(it[1]);
//         graph[it[1]].push_back(it[0]);
//     }


//     int cycles = 0;
//     int useless = 0;
//     vector <bool> mainVisited(n, false);
//     for (int i = 0; i < n; i++) {
//         vector <bool> visited(n, false);
//         if (mainVisited[i] == false) {
//             detector(i, i, graph, mainVisited, visited, useless);
//             cycles++;
//         }
//     }
//     cout << cycles << endl;

//     return cycles;
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

        int countUnits() {
            int counter = 0;
            for (int i = 0; i < parent.size(); i++) {
                if (parent[i] == i) {
                    counter++;
                }
            }

            return counter;
        }
};


int makeConnected(int n, vector<vector<int>>& connections) {
    DSU hold(n);
    for (int i = 0; i < connections.size(); i++) {
        hold.U(connections[i][0], connections[i][1]);
    }        
    int independent = hold.countUnits();

    if (connections.size() < n - 1) {
        return -1;
    }

    return independent - 1;
}


int main() {
    return 0;
}
