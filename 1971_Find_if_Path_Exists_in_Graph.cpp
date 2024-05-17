#include <iostream>
#include <vector>
using namespace std;

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

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    DSU dsu(n);

    for (auto it: edges) {
        dsu.U(it[0], it[1]);
    }

    return dsu.find(source) == dsu.find(destination);
}

int main() {
    return 0;
}