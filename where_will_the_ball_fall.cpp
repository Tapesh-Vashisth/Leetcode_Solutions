#include <iostream>
#include <vector>
using namespace std;


vector<int> findBall(vector<vector<int>>& grid){
    vector <int> ans;
    int rows = grid.size();
    int columns = grid[0].size();

    for (int j = 0; j < columns; j++){
        int i = 0;
        int current_col = j;
        while ((!(grid[i][current_col] == 1 && current_col == columns - 1)) || (!(grid[i][current_col] == -1 && current_col == 0)) || (!(grid[i][current_col] == -1 && grid[i][current_col - 1] == 1)) || (!(grid[i][current_col] == 1 && grid[i][current_col + 1] == -1)) || (!(i == rows))){
            if (grid[i][current_col] == 1){
                current_col += 1;
            }else{
                current_col -= 1;
            }   

            i++;
        }

        if (i == rows){
            ans.push_back(current_col);
        }else{
            ans.push_back(-1);
        }
    }

    return ans;
}


int main(){
    vector <vector<int>> inp = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    findBall(inp);
    return 0;
}