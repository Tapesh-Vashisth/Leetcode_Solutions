#include <iostream>
#include <vector>
using namespace std;

double total;
double found;

void helper(int n, int k, int moves, int x, int y){
    vector <pair<int, int>> offsets = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};
    if (!((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 1))){
            total++;
    }else if (moves == k){
        if ((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 1)){
            found++;
        }
        total++;
    }else{
        for (int i = 0; i < offsets.size(); i++){
            helper(n, k, moves + 1, x + offsets[i].first, y + offsets[i].second);
        }
    }
}

double knightProbability(int n, int k, int row, int column) {
    total = 0;
    found = 0;
    helper(n, k, 0, row, column);
    double ans = found/total;
    return ans;
}

int main(){
    return 0;
}