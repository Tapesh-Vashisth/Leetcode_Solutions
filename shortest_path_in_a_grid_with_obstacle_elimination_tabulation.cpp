#include <iostream>
#include <vector>
#include <queue>
using namespace std;


pair <int, int> findmin(vector<vector<int>>& grid, vector <vector <pair <int, int>>>& check, int x, int y){
    pair <int, int> mn = {1 << 30, 0};
    // left
    if (y > 0 && check[x][y - 1].first != -2 && !(grid[x][y] == 1 && check[x][y - 1].second )){    
    }

    // right 
    if (y < check[0].size() - 1 && check[x][y + 1].first != -2){

    }

    // up 
    if (x > 0 && check[x - 1][y].first != -2){

    }

    // down 
    if (x < check.size() - 1 && check[x + 1][y].first != -2){

    }

}


int shortestPath(vector<vector<int>>& grid, int k) {
    vector <vector <pair <int, int>>> storage(grid.size(), vector <pair <int, int>> (grid[0].size(), {-2, -2}));
    storage[0][0] = {0, k};
    // for (int i = 0; i < storage.size(); i++){
    //     for (int j = 0; j < storage[i].size(); j++){
    //         cout << storage[i][j].first << " " << storage[i][j].second << endl;
    //     }
    // }
    queue <pair<int, int>> holder;
    for (int i = 0; i < storage.size(); i++){
        for (int j = 0; j < storage[i].size(); j++){
            holder.push({i, j});
        }
    }


    while (!holder.empty()){
        pair <int, int> temp = holder.front();
        holder.pop();
        int x = temp.first;
        int y = temp.second;
        pair <int, int> mn = findmin(grid, x, y);
    }

    return 0;
}

int main(){
    return 0;
}