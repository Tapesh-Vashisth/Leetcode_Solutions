#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool checker(vector <vector <char>>& board, int x, int y, char value){
    // horizontal
    for (int i = 0; i < board[0].size(); i++){
        if (board[x][i] == value){
            return false;
        }
    }
    // vertical 
    for (int i = 0; i < board.size(); i++){
        if (board[i][y] == value){
            return false;
        }
    }
    // cubic
    int starting_x = (x/3)*3;
    int starting_y = (y/3)*3;
    
    for (int i = starting_x; i <= starting_x + 2; i++){
        for (int j = starting_y; j <= starting_y + 2; j++){
            if (board[i][j] == value){
                return false;
            }
        }
    }

    return true;
}

vector <vector<char>> sudoku_helper(vector <vector<char>>& board, int x, int y){
    if (x == board.size() || y == board[0].size()){
        return board;
    }else{
        if (board[x][y] == '.'){
            for (int i = 1; i < 10; i++){
                bool decider = checker(board, x, y, i);
                if (decider){
                    board[x][y] = '0' + i;
                    if (y == board[0].size() - 1){
                        sudoku_helper(board, x + 1, y);
                    }else{
                        sudoku_helper(board, x, y + 1);
                    }
                    board[x][y] = '.';
                }
            }
        }else{
            if (y == board[0].size() - 1){
                sudoku_helper(board, x + 1, y);
            }else{
                sudoku_helper(board, x, y + 1);
            }
        }
    }
}

void solveSudoku(vector<vector<char>>& board){
    vector <vector <char>> ans = sudoku_helper(board, 0, 0);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << " " << endl;
        }
        cout << endl;
    }
}

int main(){
    return 0;
}