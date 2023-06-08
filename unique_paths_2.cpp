#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector <vector <long long>> dp (n, vector <long long> (m, 0));
    
    int check = 1;
    // row wise
    for (int i = 0; i < n; i++){
        if (obstacleGrid[i][0] == 1){
            check = 0;
        }
        dp[i][0] = check;
    }

    // column wise
    check = 1; 
    for (int i = 0; i < m; i++){
        if (obstacleGrid[0][i] == 1){
            check = 0;
        }
        dp[0][i] = check;
    }

    // construction
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (obstacleGrid[i][j] == 1){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }    

    return dp[n - 1][m - 1];
}

int main(){
    vector <vector <int>> v = {{0,0,0,0,0,0,0}, {0,1,0,0,0,0,0}, {0,0,0,0,0,0,0}};
    cout << uniquePathsWithObstacles(v) << endl;
    return 0;
}