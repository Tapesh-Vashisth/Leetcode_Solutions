#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n){
    vector <vector <long long>> dp(m, vector <int> (n, 0));


    // row wise
    for (int i = 0; i < m; i++){
        dp[i][0] = 1;
    }

    // column wise 
    for (int i = 0; i < n; i++){
        dp[0, i] = 1;
    }

    // construction 
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            dp[i][j] = dp[i - 1][j] + dp[j][i - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int main(){
    return 0;
}