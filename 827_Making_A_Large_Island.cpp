#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DSU {
    public:
        vector <int> parent;
        vector <int> size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int ele) {
            if (parent[ele] == ele) {
                return ele;
            } 

            int par = find(parent[ele]);

            parent[ele] = par;

            return par;
        }

        int largest() {
            int mx = 0;
            for (auto it: size) {
                mx = max(mx, it);
            }

            return mx;
        }


        void U(int a, int b) {
            int p1 = find(a);
            int p2 = find(b);

            parent[a] = p1;
            parent[b] = p2;
            
            if (p1 != p2) {
                parent[p1] = p2;
                size[p2] += size[p1];
            }
        }

        void print() {
            for (int i = 0; i < parent.size(); i++) {
                cout << i << " " << parent[i] << endl;
            }
        }
};

int largestIsland(vector<vector<int>>& grid) {
    DSU dsu(grid.size() * grid[0].size());

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j]) {
                vector <int> xs = {0, 0, 1, -1};
                vector <int> ys = {1, -1, 0, 0};

                for (int k = 0; k < 4; k++) {
                    int holdx = i + xs[k];
                    int holdy = j + ys[k];

                    if (holdx >= 0 && holdx < grid.size() && holdy >= 0 && holdy < grid[0].size() && grid[holdx][holdy]) {
                        dsu.U(i * grid[i].size() + j, holdx * grid[i].size() + holdy);
                    }
                }
            }
        }
    }

    int ans = dsu.largest();

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) {
                vector <int> xs = {0, 0, 1, -1};
                vector <int> ys = {1, -1, 0, 0};

                int total = 1;

                unordered_map <int, int> hash; 
                for (int k = 0; k < 4; k++) {
                    int holdx = i + xs[k];
                    int holdy = j + ys[k];
                    if (holdx >= 0 && holdx < grid.size() && holdy >= 0 && holdy < grid[0].size() && grid[holdx][holdy]) {
                        int cont = dsu.find(holdx * grid[0].size() + holdy);
                        if (hash[cont] == 0) {
                            hash[cont] = 1;
                            total += dsu.size[cont];
                        }
                    }
                }

                ans = max(ans, total);
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}