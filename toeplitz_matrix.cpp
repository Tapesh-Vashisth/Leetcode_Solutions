#include <iostream>
#include <vector>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix){
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++){
            if (j + 1 < matrix[i].size() || i + 1 < matrix.size()){
                if (matrix[i + 1][j + 1] != matrix[i][j]){
                    return false;
                }
            }
        }
    }

    return true;
}

int main(){
    return 0;
}