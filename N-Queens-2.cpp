#include <iostream>
#include <vector>
using namespace std;

bool check(pair <int, int> p, vector <pair<int, int>>& v){
    bool decider = true;
    for (int i = 0; i < v.size(); i++){
        if (abs(p.first - v[i].first) == abs(p.second - v[i].second)){
            decider = false;
            break;
        }else if(p.first == v[i].first || p.second == v[i].second){
            decider = false;
            break;
        }
    }
    return decider;
}

int NQueenHelper(int n, int i, vector <pair<int, int>> &v){
    if (i >= n){
        return 1;
    }else{
        int total = 0;
        for (int j = 0; j < n; j++){
            bool decider = check(pair <int, int> {i, j}, v);
            if (decider){
                v.push_back(pair<int, int> {i, j});
                total += NQueenHelper(n, i + 1, v);
                v.pop_back();
            }
        }

        return total;
    }
}

int totalNQueens(int n) {
    vector <pair<int, int>> v;
    return NQueenHelper(n, 0, v);
}

int main(){
    cout << totalNQueens(1) << endl;
    return 0;
}