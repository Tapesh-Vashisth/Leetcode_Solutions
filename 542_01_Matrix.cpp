#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue <pair <int, int>> store;
    vector <vector <bool>> visited(mat.size(), vector <bool> (mat[0].size(), true));    
    vector <vector <int>> ans(mat.size(), vector <int> (mat[0].size(), 0));
    int counter = 0;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 0) {
                visited[i][j] = false;
                store.push({i, j});
                counter++;
            }        
        }
    }
    
    int turns = 1;
    while (!store.empty()) {
        int temp = 0;
        while (counter--) {
            pair <int, int> hold = store.front();
            store.pop();
            
            vector <int> x = {0, 0, 1, -1};
            vector <int> y = {1, -1, 0, 0};
            
            for (int i = 0; i < 4; i++) {
                if (hold.first + x[i] >= 0 && hold.first + x[i] < mat.size() && hold.second + y[i] >= 0 && hold.second + y[i] < mat[0].size()) {
                    if (visited[hold.first + x[i]][hold.second + y[i]]) {
                        visited[hold.first + x[i]][hold.second + y[i]] = false;
                        ans[hold.first + x[i]][hold.second + y[i]] = turns;
                        store.push({hold.first + x[i], hold.second + y[i]});
                        temp++;
                    }
                }
            }
        }
        
        turns++;
        counter = temp;
    }
    
    return ans;
}

int main() {
    return 0;
}