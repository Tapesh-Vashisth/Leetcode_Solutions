#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector <int> ans;
    // 1 --> right 
    // 2 --> down
    // 3 --> left
    // 4 --> up

    int dir = 1;
    int x = 0;
    int y = 0;
    while (true) {
        ans.push_back(matrix[x][y]);
        matrix[x][y] = -200;
        if (dir == 1) {
            if ((x < 0 || x >= matrix.size()) || (y + 1 < 0 || y + 1 >= matrix[0].size()) || matrix[x][y + 1] != -200) {
                dir = 2;
            } else {
                y++;
                continue;
            }
        }

        if (dir == 2) { 
            if ((x + 1 < 0 || x + 1 >= matrix.size()) || (y < 0 || y >= matrix[0].size()) || matrix[x + 1][y] != -200) {
                dir = 3;
            } else {
                x++;
                continue;
            }
        }

        if (dir == 3) { 
            if ((x < 0 || x >= matrix.size()) || (y - 1 < 0 || y - 1 >= matrix[0].size()) || matrix[x][y - 1] != -200) {
                dir = 4;
            } else {
                y--;
                continue;
            }
        }

        if (dir == 4) {
            if ((x - 1 < 0 || x - 1  >= matrix.size()) || (y + 1 < 0 || y + 1 >= matrix[0].size()) || matrix[x - 1][y] != -200) {
                dir = 1;
            } else {
                x--;
                continue;
            }
        } 

        break;
    }

    return ans;
}

int main() {
    return 0;
}