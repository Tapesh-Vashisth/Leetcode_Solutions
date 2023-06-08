#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void helper(vector <vector <char>> & board, int x, int y, vector <vector <bool>> & visited) {
    queue <pair <int, int>> store;
    store.push({x, y});

    while (!store.empty()) {
        pair <int, int> hold = store.front();
        store.pop();

        if (visited[hold.first][hold.second]) {
            visited[hold.first][hold.second] = false;

            vector <int> xs = {1, -1, 0, 0};
            vector <int> ys = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int holdx = hold.first + xs[i];
                int holdy = hold.second + ys[i];

                if (holdx >= 0 && holdx < board.size() && holdy >= 0 && holdy < board[0].size() && board[holdx][holdy] == 'O') {
                    store.push({holdx, holdy});
                }
            }
        }
    }
}

void solve(vector<vector<char>>& board) {
    vector <vector <bool>> visited(board.size(), vector <bool> (board[0].size(), true));

    // move through the borders
    for (int i = 0; i < board.size(); i++) {
        if (board[i][0] == 'O' && visited[i][0]) {
            helper(board, i, 0, visited);
        }

        if (board[i][board[i].size() - 1] == 'O' && visited[i][board[i].size() - 1]) {
            helper(board, i, board[i].size() - 1, visited);
        }
    }

    for (int j = 0; j < board[0].size(); j++) {
        if (board[0][j] == 'O' && visited[0][j]) {
            helper(board, 0, j, visited);
        }

        if (board[board.size() - 1][j] == 'O' && visited[board.size() - 1][j]) {
            helper(board, board.size() - 1, j, visited);
        }
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (visited[i][j]) {
                board[i][j] = 'X';
            }
        }
    }
}

int main() {
    return 0;
}