#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat){
    int row = mat.size();
    int column = mat[0].size();
    for (int i = row - 1; i >= 0; i--){
        int hash[100] = {0};
        int x = i;
        int y = 0;
        while (x < row && y < column){
            hash[mat[x][y] - 1]++;
            x++;
            y++;
        }

        x = i;
        y = 0;

        for (int j = 0; j < 100; j++){
            while (hash[j] != 0){
                mat[x][y] = j + 1;
                hash[j]--;
                x++;
                y++;
            }
        }
    }

    for (int i = 1; i < column; i++){
        int hash[100] = {0};
        int x = 0;
        int y = i;
        while (x < row && y < column){
            hash[mat[x][y] - 1]++;
            x++;
            y++;
        }

        x = 0;
        y = i;

        for (int j = 0; j < 100; j++){
            while (hash[j] != 0){
                mat[x][y] = j + 1;
                hash[j]--;
                x++;
                y++;
            }
        }
    }

    return mat;
}

int main(){
    vector <vector <int>> v = {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};
    v = diagonalSort(v);
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[0].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}