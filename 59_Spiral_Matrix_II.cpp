#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) { 
    vector <vector <int>> ans(n, vector <int> (n , 0));
    // 1 --> right 
    // 2 --> down
    // 3 --> left
    // 4 --> up

    int dir = 1;
    int x = 0;
    int y = 0;
    int counter = 1;
    while (true) {
        ans[x][y] = counter++;
        if (dir == 1) {
            if ((x < 0 || x >= n) || (y + 1 < 0 || y + 1 >= n)) {
                dir = 2;
            } else {
                y++;
                continue;
            }
        }

        if (dir == 2) { 
            if ((x + 1 < 0 || x + 1 >= n) || (y < 0 || y >= n)) {
                dir = 3;
            } else {
                x++;
                continue;
            }
        }

        if (dir == 3) { 
            if ((x < 0 || x >= n) || (y - 1 < 0 || y - 1 >= n)) {
                dir = 4;
            } else {
                y--;
                continue;
            }
        }

        if (dir == 4) {
            if ((x - 1 < 0 || x - 1 >= n) || (y < 0 || y >= n)){ 
                dir = 1;
            } else {
                x--;
                continue;
            }
        } 

        if (dir == 1) {
            if ((x < 0 || x >= n) || (y + 1 < 0 || y + 1 >= n)) {
                dir = 2;
            } else {
                y++;
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