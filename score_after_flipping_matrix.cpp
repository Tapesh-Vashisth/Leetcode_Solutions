#include <iostream>
#include <vector>
using namespace std;


inline int power(int a, int b)
{
       int x = 1;
       while (b)
       {
               if (b & 1) x *= a;
               a *= a;
               b >>= 1;
       }
       return x;
}


int matrixScore(vector<vector<int>>& grid) {
    // checking rows 
    for (int i = 0; i < grid.size(); i++){
        if (grid[i][0] == 0){
            for (int j = 0; j < grid[i].size(); j++){
                grid[i][j] = !grid[i][j];
            }
        }else{
            ;
        }
    }

    // checking columns
    for (int i = 0; i < grid[0].size(); i++){
        int zeros = 0;
        int ones = 0;
        for (int j = 0; j < grid.size(); j++){
            if (grid[j][i] == 0){
                zeros++;
            }else{
                ones++;
            }
        }

        if (zeros > ones){
            for (int j = 0; j < grid.size(); j++){
                grid[j][i] = !grid[j][i];
            }
        }

    }

    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    int ans = 0;
    for (int i = 0; i < grid.size(); i++){
        int index = 0;
        for (int j = grid[i].size() - 1; j >= 0; j--){
            ans = ans + grid[i][j] * power(2, index);
            index++;
        }
    }

    return ans;
}


int main(){
    vector <vector<int>> v = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout << matrixScore(v) << endl;
    return 0;
}