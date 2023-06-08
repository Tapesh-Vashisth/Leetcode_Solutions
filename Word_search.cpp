#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// directions
// start: 0
// right: 1
// left: 2
// down: 3
// up: 4

bool check(vector <vector <char>>& board, string word, int x, int y, int direction, vector <pair<int, int>> & used){
    if (find(used.begin(), used.end(), pair <int, int> {x, y}) != used.end()){
        if (word.size() == 1){
            if (word[0] == board[x][y]){
                return true;    
            }else{
                return false;
            }  
        }else{
            bool decider = false;
            string pass = word.substr(1);
            int control = 0;
            // right
            if (direction != 2){
                if (y < board[0].size() - 1){
                    control = 1;
                    used.push_back(pair<int, int> {x, y});
                    decider = check(board, pass, x, y + 1, 1, used);
                    used.pop_back();
                }    
            }
            

            // left
            if (direction != 1){
                if (decider == false){
                    if (y > 0){
                        control = 1;
                        used.push_back(pair<int, int> {x, y});
                        decider = check(board, pass, x, y - 1, 2, used);
                        used.pop_back();
                    }
                }    
            }
            

            // down
            if (direction != 4){
                if (decider == false){
                    if (x > 0){
                        control = 1;
                        used.push_back(pair<int, int> {x, y});
                        decider = check(board, pass, x - 1, y, 3, used);
                        used.pop_back();
                    }
                }    
            }
            

            // up
            if (direction != 3){
                if (decider == false){
                    if (x < board.size() - 1){
                        control = 1;
                        used.push_back(pair<int, int> {x, y});
                        decider = check(board, pass, x + 1, y, 4, used);
                        used.pop_back();
                    }
                }    
            }
            

            if (decider){
                if (board[x][y] != word[0]){
                    decider = false;
                }
            }
            
            if (control == 0){
                decider = false;
            }

            return decider;
        }
    }else{
        return false;
    }
}

bool exist(vector<vector<char>>& board, string word){
    bool decider = false;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            if (board[i][j] == word[0]){
                bool temp = check(board, word, i, j, 0, vector <pair<int, int>> {});
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