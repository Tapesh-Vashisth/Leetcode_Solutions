#include <iostream>
#include <vector>
using namespace std;

pair <int, int> cordinates (int current, int n) {
    pair <int, int> coord;
    coord.first = current/n;
    if (coord.first % 2) {
        coord.second = n - (current % n) - 1;
    } else {
        coord.second = current % n;
    }

    return coord;
}

int helper(vector <vector <int>>& board, int current, int n) {
    pair <int, int> coord = cordinates(current, n);
    if (current == n*n) {
        return 0;
    }

    if (current > n*n) {
        return -1;
    }

    for (int i = 1; i <= 6; i++) {
        
    }
}

int snakesAndLadders(vector<vector<int>>& board) {
    int ans = helper(board, 0, board.size());
    return ans;
}

int main() {
    return 0;
}