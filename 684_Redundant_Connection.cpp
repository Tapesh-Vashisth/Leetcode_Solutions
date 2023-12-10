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


        bool U(int a, int b) {
            int p1 = find(a);
            int p2 = find(b);

            parent[a] = p1;
            parent[b] = p2;
            
            if (p1 != p2) {
                parent[p1] = p2;
                return true;
            } else {
                return false;
            }
        }

        void print() {
            for (int i = 0; i < parent.size(); i++) {
                cout << i << " " << parent[i] << endl;
            }
        }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    DSU dsu(edges.size());
    vector <int> ans;
    for (auto it: edges) {
        if (dsu.U(it[0] - 1, it[1] - 1)) {
            ;
        } else {
            ans.push_back(it[0]);
            ans.push_back(it[1]);
            break;
        }
    }        

    return ans;
}

int main() {
    return 0;
}