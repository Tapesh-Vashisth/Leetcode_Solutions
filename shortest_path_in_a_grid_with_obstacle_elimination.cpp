#include <iostream>
#include <vector>
using namespace std;


vector <vector <int>> memory;

int helper(vector<vector<int>>& grid, vector <vector <int>>& visited, int obstacles, int x, int y){
    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || visited[y][x] == 1 || (obstacles == 0 && grid[y][x] == 1)){
        return -1;
    }else if(x == grid[0].size() - 1 && y == grid.size() - 1){
        return 0;
    }else{
        if (memory[y][x] != -1){
            return memory[y][x];
        }
        int mn = 1 << 30;
        visited[y][x] = 1;
        int up = helper(grid, visited, grid[y][x] == 1 ? obstacles - 1: obstacles, x, y - 1);
        if (up != -1){
            mn = min(up, mn);
        }
        int down = helper(grid, visited, grid[y][x] == 1 ? obstacles - 1: obstacles, x, y + 1);
        if (down != -1){
            mn = min(down, mn);
        }
        int left = helper(grid, visited, grid[y][x] == 1 ? obstacles - 1: obstacles, x - 1, y);
        if (left != -1){
            mn = min(left, mn);
        }
        int right = helper(grid, visited, grid[y][x] == 1 ? obstacles - 1: obstacles, x + 1, y);
        if (right != -1){
            mn = min(right, mn);
        }
        visited[y][x] = 0;

        memory[y][x] = mn == (1 << 30) ? -1: mn + 1;
        return memory[y][x];
    }
}

int shortestPath(vector<vector<int>>& grid, int k) {
    memory = vector <vector <int>>(grid.size(), vector <int> (grid[0].size(), -1));
    vector <vector <int>> visited(grid.size(), vector <int> (grid[0].size(), 0));
    int ans = helper(grid, visited, k, 0, 0);
    return ans;
}

int main(){
    return 0;
}