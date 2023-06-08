#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int horizontal[9] = {0};
    int vertical [9] = {0};
    int block[9] = {0};
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); i++){
            horizontal[board[i][j]]++;
            vertical[board[j][i]]++;
        }

        for (int i = 0; i < 9; i++){
            if (horizontal[i] > 1 || vertical[i] > 1){
                return false;
            }
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                for (int q = 0; q < 3; q++){
                    block[board[3*i + k][3*j + q]]++;
                }
            }
            for (int i = 0; i < 9; i++){
                if (horizontal[i] > 1 || vertical[i] > 1){
                    return false;
                }
            }
        }
    }

    return true;
}


int main(){
    return 0;
}