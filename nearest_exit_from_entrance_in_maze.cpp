#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int count = 0;
// // dp recursion 
// int helper(vector <vector<char>>& maze, vector <vector <int>>& visited, int x, int y){
//     if (count != 0 && x == maze.size() - 1 || y == maze[0].size() - 1 || x == 0 || y == 0){
//         return 0;
//     } else {
//         count = 1;
//         int mn = 1000;
//         visited[x][y] = 1;
//         // right 
//         if (maze[x][y + 1] != '+' && visited[x][y + 1] == 0){
//             mn = min(helper(maze, visited, x, y + 1), mn);
//         }
//         // left 
//         if (maze[x][y - 1] != '+' && visited[x][y - 1] == 0){
//             mn = min(helper(maze, visited, x, y - 1), mn);
//         }

//         // up
//         if (maze[x - 1][y] != '+' && visited[x - 1][y] == 0){
//             mn = min(helper(maze, visited, x - 1, y), mn);
//         }

//         // down 
//         if (maze[x + 1][y] != '+' && visited[x + 1][y] == 0){
//             mn = min(helper(maze, visited, x + 1, y), mn);
//         }

//         visited[x][y] = 0;

//         cout << x <<  " "  << y <<  " "  << mn << endl;
//         if (mn != 1000){
//             return mn + 1;
//         }else{
//             return 1000;
//         }
//     }
// }

// int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
//     int x = entrance[0];
//     int y = entrance[1];
//     vector <vector <int>> visited(maze.size(), vector <int> (maze[0].size(), 0));
//     int ans = helper(maze, visited, x, y);
//     if (ans == 1000){
//         return -1;
//     }
//     return ans;
// }


// bfs approach 

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance){
    queue <pair <int, int>> store;
    pair <int, int> p;
    p.first = entrance[0];
    p.second = entrance[1];
    vector <vector <int>> matrix(maze.size(), vector <int> (maze[0].size(), 100000));
    matrix[p.first][p.second] = 0;
    store.push(p);
    while (!store.empty()){
        pair <int, int> hold = store.front();
        store.pop();
        int source = matrix[hold.first][hold.second];
        int dist = source + 1;
        // left 
        if (hold.second - 1 >= 0 && dist < matrix[hold.first][hold.second - 1] && maze[hold.first][hold.second - 1] != '+'){
            matrix[hold.first][hold.second - 1] = dist;
            store.push({hold.first, hold.second - 1});
        }

        // right 
        if (hold.second + 1 < maze[0].size() && dist < matrix[hold.first][hold.second + 1] && maze[hold.first][hold.second + 1] != '+'){
            matrix[hold.first][hold.second + 1] = dist;
            store.push({hold.first, hold.second + 1});
        }

        // up 
        if (hold.first - 1 >= 0 && dist < matrix[hold.first - 1][hold.second] && maze[hold.first - 1][hold.second] != '+'){
            matrix[hold.first - 1][hold.second] = dist;
            store.push({hold.first - 1, hold.second});
        }

        // down 
        if (hold.first + 1 < maze.size() && dist < matrix[hold.first + 1][hold.second] && maze[hold.first + 1][hold.second] != '+'){
            matrix[hold.first + 1][hold.second] = dist;
            store.push({hold.first + 1, hold.second});
        }
    }

    int mn = 100000;

    for (int i = 0; i < maze.size(); i++){
        if (matrix[i][0] < mn){
            mn=matrix[i][0]<mn;
        }

        if (matrix[i][matrix[0].size() - 1]<mn){
            mn=matrix[i][matrix[0].size() - 1];
        }
    }

    for (int i = 0; i < maze[0].size(); i++){
        if (matrix[0][i]<mn){
            mn=matrix[0][i]<mn;
        }

        if (matrix[matrix.size() - 1][i]<mn){
            mn=matrix[matrix.size() - 1][i];
        }
    }

    if (mn == 100000){
        return -1;
    }

    return mn;
}

int main(){
    vector<vector<char>> maze = {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    vector<int> entrance = {1, 2};

    cout << nearestExit(maze, entrance) << endl;
    return 0;
}


// 0    +    +    +    +    +    +    +    +    +    +   
// 1    +    .    .    .    .    .    +    +    +    +   
// 2    +    .    +    +    +    .    +    .    +    +   
// 3    +    .    +    +    +    .    +    .    +    +   
// 4    +    .    +    +    +    .    +    .    +    +   
// 5    +    .    +    +    +    .    +    .    +    +   
// 6    +    .    +    +    +    .    +    .    +    +   
// 7    +    .    +    +    +    .    +    .    +    +   
// 8    +    .    +    +    .    .    +    .    +    +   
// 9    +    .    +    +    +    .    +    .    +    +   
// 10   +    .    +    +    +    .    +    .    +    +   
// 11   +    .    +    +    +    .    +    +    +    +   
// 12   +    .    +    +    +    .    +    +    +    +   
// 13   +    .    .    .    .    .    .    .    .    .   
// 14   +    +    +    +    +    +    +    +    +    + 
// [8,5]
    
// 0    -1   -1   -1    -1     -1     -1     -1     -1     -1     -1     
// 1    -1   20   21    22     23     24     -1     -1     -1     -1     
// 2    -1   19   -1    -1     -1     25     -1     -1     -1     -1     
// 3    -1   18   -1    -1     -1     26     -1     -1     -1     -1     
// 4    -1   17   -1    -1     -1     27     -1     -1     -1     -1     
// 5    -1   16   -1    -1     -1     28     -1     -1     -1     -1     
// 6    -1   15   -1    -1     -1     29     -1     -1     -1     -1     
// 7    -1   14   -1    -1     -1     30     -1     -1     -1     -1     
// 8    -1   13   -1    -1 100000     31     -1     -1     -1     -1     
// 9    -1   12   -1    -1     -1 100000     -1     -1     -1     -1     
// 0    -1   11   -1    -1     -1 100000     -1     -1     -1     -1     
// 1    -1   10   -1    -1     -1 100000     -1     -1     -1     -1     
// 2    -1    9   -1    -1     -1 100000     -1     -1     -1     -1     
// 3    -1    8    7     6      5      4      3      2      1     -1     
// 4    -1   -1   -1    -1     -1     -1     -1     -1     -1     -1     