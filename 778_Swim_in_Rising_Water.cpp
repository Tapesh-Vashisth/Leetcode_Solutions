#include <iostream>
#include <vector>
using namespace std;

int val(int i, int j, int n) {
    return (i * n + j);
}

class DSU {
    public: 
        vector <int> parents;
        int n;

        DSU (int n) {
            this->n = n;
            for (int i = 0; i < n; i++) {
                parents.push_back(i);
            }
        }

        int getParent(int x) {
            int hold = parents[x];

            if (hold != x) {
                return getParent(hold);
            }

            return hold;
        }

        void U(int x, int y) {
            int parentX = getParent(x);
            int parentY = getParent(y);

            parents[parentX] = parentY;
        }
};

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector <pair <int, int>> hash(n * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hash[grid[i][j]] = {i, j};
        }
    }   

    vector <vector <bool>> water(n, vector <bool> (n, false));     

    vector <int> xs = {0, 0, 1, -1};
    vector <int> ys = {1, -1, 0, 0};

    DSU dsu(n*n);
    int time = 0;
    while (true) {
        pair <int, int> pos = hash[time];

        for (int i = 0; i < 4; i++) {
            int holdx = pos.first + xs[i];
            int holdy = pos.second + ys[i];

            if (holdx >= 0 && holdx < n && holdy >= 0 && holdy < n) {
                if (water[holdx][holdy]) {
                    dsu.U(val(holdx, holdy, n), val(pos.first, pos.second, n));
                }
            }
        }

        water[pos.first][pos.second] = true;

        if (dsu.getParent(0) == dsu.getParent((n * n) - 1)) {
            break;
        }

        time++;
    }

    return time;
}

int main() {
    return 0;
}