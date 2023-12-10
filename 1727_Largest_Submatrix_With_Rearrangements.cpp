#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestSubmatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    vector <vector <int>> store(rows, vector <int> (columns, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == 0) {
                store[i][j] = 0;
            } else {
                if (i - 1 >= 0) {
                    store[i][j] = store[i - 1][j] + 1;
                } else {
                    store[i][j] = 1;
                }
            }
        }
    }        

    int ans = 0;

    for (int i = 0; i < rows; i++) {
        sort(store[i].begin(), store[i].end());
        for (int j = 0; j < columns; j++) {
            ans = max(ans, store[i][j] * (columns - j));
        }
    }

    return ans;
}

int main() {
    return 0;
}