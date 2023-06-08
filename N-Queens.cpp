#include <iostream>
#include <vector>
using namespace std;

vector <vector<string>> ans;

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

void NQueenHelper(int n, int i, vector <pair<int, int>> &v, vector<string> & make){
    if (i >= n){
        ans.push_back(make);
    }else{
        for (int j = 0; j < n; j++){
            bool decider = check(pair <int, int> {i, j}, v);
            if (decider){
                v.push_back(pair<int, int> {i, j});
                make[i][j] = 'Q';
                NQueenHelper(n, i + 1, v, make);
                make[i][j] = '.';
                v.pop_back();
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector <pair<int, int>> v;
    vector<string> real(n);
    for (int  i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            real[i].push_back('.');
        }
    }
    NQueenHelper(n, 0, v, real);
    for (auto a: ans){
        for (auto b: a){
            cout << b << endl;
        }
        cout << endl;
    }
    return ans;
}

int main(){
    solveNQueens(4);
    return 0;
}