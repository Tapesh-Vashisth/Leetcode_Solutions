#include <iostream>
#include <vector>
using namespace std;

int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2){
    int rows = img1.size();
    int columns = img1[0].size();
    int mn = 1 << 30;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            int hold = 0;
            for (int a = i; a < rows; a++){
                for (int b = j; b < columns; b++){
                    if (img1[a][b] == img2[i - a][j - b]){
                        hold++;
                    }
                }
            }

            if (hold < mn){
                mn = hold;
            }
        }
    }

    return mn;
}

int main(){
    return 0;
}