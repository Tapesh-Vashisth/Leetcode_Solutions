#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> v;
vector <int> temp;

void combinationSum(vector<int>& candidates, int target, int current){
    if (target == 0){
        v.push_back(temp);
    }else if(target < 0){
        ;
    }else{
        for (int i = current; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i);
            temp.pop_back();
        }
    }
}

int main(){
    vector <int> test = {2, 3, 6, 7};
    combinationSum(test, 7, 0);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}