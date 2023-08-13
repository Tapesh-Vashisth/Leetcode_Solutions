#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool check(vector <vector <char>>& board, string & word, int index, int x, int y, vector <vector <bool>> & visited){
    if (visited[x][y]) {
        if (index == word.size() - 1) {
            return true;
        }

        visited[x][y] = false;

        // up
        if (x - 1 >= 0 && board[x - 1][y] == word[index + 1]) {
            bool first = check(board, word, index + 1, x - 1, y, visited);
            if (first) return true;
        } 

        // down 
        if (x + 1 < board.size() && board[x + 1][y] == word[index + 1]) {
            bool second = check(board, word, index + 1, x + 1, y, visited);
            if (second) return true;
        }

        // left 
        if (y - 1 >= 0 && board[x][y - 1] == word[index + 1]) {
            bool third = check(board, word, index + 1, x, y - 1, visited);
            if (third) return true;
        }

        // right 
        if (y + 1 < board[0].size() && board[x][y + 1] == word[index + 1]) {
            bool fourth = check(board, word, index + 1, x, y + 1, visited);
            if (fourth) return true;
        }
        
        visited[x][y] = true;
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word){
    bool decider = false;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            if (board[i][j] == word[0]){
                vector <vector <bool>> visited (board.size(), vector <bool> (board[0].size(), true));
                bool temp = check(board, word, 0, i, j, visited);
                if (temp){
                    decider = true;
                    break;
                }
            }
        }

        if (decider){
            break;
        }
    }

    return decider;
}


int main(){
    return 0;
}