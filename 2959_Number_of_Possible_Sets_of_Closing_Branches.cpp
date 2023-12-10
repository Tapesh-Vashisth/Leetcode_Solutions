#include <iostream>
#include <vector>
using namespace std;

int helper(int current, int n, int maxDistance, vector <bool> & taken, vector <vector <int>> & roads) {
    if (current == n) {
        vector <vector <int>> mat(n, vector <int> (n, INT32_MAX));

        for (int i = 0; i < n; i++) {
            mat[i][i] = 0;
        }

        for (auto it: roads) {
            if ((taken[it[0]] && taken[it[1]])) {
                mat[it[0]][it[1]] = min(mat[it[0]][it[1]], it[2]);
                mat[it[1]][it[0]] = min(mat[it[1]][it[0]], it[2]);
            }
        }
        

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((mat[k][j] != INT32_MAX && mat[i][k] != INT32_MAX) && mat[i][j] > (mat[i][k] + mat[k][j])) {
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (taken[i]) {
                for (int j = 0; j < n; j++) {
                    if (taken[j]) {
                        if (mat[i][j] == INT32_MAX || mat[i][j] > maxDistance) {
                            return 0;
                        }    
                    }
                }   
            }
        }

        return 1;
    }

    int ret = 0;
    // take 
    taken[current] = true;
    ret += helper(current + 1, n, maxDistance, taken, roads);

    // not take 
    taken[current] = false;
    ret += helper(current + 1, n, maxDistance, taken, roads);

    return ret;
}

int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
    vector <bool> taken(n, false);

    return helper(0, n, maxDistance, taken, roads);
}

int main() {
    return 0;
}