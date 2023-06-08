#include <iostream>
#include <vector>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
    int total = 0;
    int minus = 0;
    int mn = INT32_MAX;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); i++) {
            total += abs(matrix[i][j]);
            if (matrix[i][j] < 0) {
                minus++;
            }

            mn = min(abs(matrix[i][j]), mn);
        }
    }

    if (minus%2 == 0) {
        return total;
    } else {
        return total - mn;
    }
}

int main() {
    return 0;
}