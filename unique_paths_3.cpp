#include <iostream>
#include <vector>
using namespace std;

bool check_visited(vector <vector <int>>& grid, vector <vector <int>>& visited){
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[0].size(); j++){
            if (grid[i][j] == 0){
                if (visited[i][j] == 0){
                    return false;
                }
            }
        }
    }

    return true;
}

int helper(vector <vector <int>>& grid, int x, int y, vector <vector <int>>& visited){
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()){
        return 0;
    }else if (grid[x][y] == -1){
        return 0;
    }else if (grid[x][y] == 0){
        if (visited[x][y] == 1){
            return 0;
        }else{
            int total = 0;
            visited[x][y] = 1;

            // left 
            total += helper(grid, x, y - 1, visited);

            // right 
            total += helper(grid, x, y + 1, visited);

            // up 
            total += helper(grid, x - 1, y, visited);

            // down 
            total += helper(grid, x + 1, y, visited);

            visited[x][y] = 0;

            return total;
        }
    }else if(grid[x][y] == 2){
        if (check_visited(grid, visited)){
            return 1;
        }else{
            return 0;
        }
    }

    return 0;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    vector <vector <int>> visited = grid;
    int x, y;
    for (int i = 0; i < grid.size(); i++){
        bool break_check = false;
        for (int j = 0; j < grid[0].size(); j++){
            if (grid[i][j] == 1){
                x = i;
                y = j;
                break_check = true;
                break;
            }
        }
        if (break_check){
            break;
        }
    }

    visited[x][y] = 0;
    
    return helper(grid, x, y, visited);
}

int main(){
    return 0;
}