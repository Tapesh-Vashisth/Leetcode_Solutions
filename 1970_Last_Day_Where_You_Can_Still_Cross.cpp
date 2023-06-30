#include <iostream>
#include <vector>
using namespace std;

class DSU {
    private:
        vector <int> parent;
        vector <pair<int, int>> borders;
        int col;
    public:
        DSU(int n, vector <vector <int>> & cells, int col) {
            this->col = col;
            parent.resize(n);
            borders.resize(n);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
                borders[i] = {cells[i][1] - 1, cells[i][1] - 1};
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


        bool U(int a, int b) {

            int p1 = find(a);
            int p2 = find(b);

            parent[a] = p1;
            parent[b] = p2;
            

            if (p1 != p2) {
                parent[p1] = p2;
            }

            borders[p2].first = min(borders[p2].first, borders[p1].first);
            borders[p2].second = max(borders[p2].second, borders[p1].second);

            if (borders[p2].first == 0 && borders[p2].second == col - 1) {
                return true;
            } 

            return false;
        }

        void print() {
            for (int i = 0; i < parent.size(); i++) {
                cout << i << " " << parent[i] << endl;
            }
        }
};

int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    DSU dsu(row * col, cells, col);
    
    vector <vector <int>> store(row, vector <int> (col, -1));

    vector <pair <int, int>> check = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (int i = 0; i < cells.size(); i++) {
        int x = cells[i][0] - 1;
        int y = cells[i][1] - 1;

        for (auto it: check) {
            int holdx = x + it.first;
            int holdy = y + it.second;

            if (holdx >= 0 && holdx < row && holdy >= 0 && holdy < col) {
                if (store[holdx][holdy] != -1) {
                    bool decider = dsu.U(i, store[holdx][holdy]);
                    if (decider) {
                        return i;
                    }
                }
            }
        }

        store[cells[i][0] - 1][cells[i][1] - 1] = i;
    }

    return cells.size() - 1;
}

int main() {
    return 0;
}