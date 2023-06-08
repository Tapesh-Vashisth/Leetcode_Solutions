#include <iostream>
#include <vector>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int ans = 0;
    for (int i = 0; i < mat.size(); i++) {
        ans += mat[i][i];
        if (i != mat.size() - i - 1) {
            ans += mat[i][mat.size() - i - 1];
        }
    }

    return ans;
}

int main() {
    return 0;
}