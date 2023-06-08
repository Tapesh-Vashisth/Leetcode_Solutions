#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> helper(int k, int n, int current){
    if (n < 0 || k < 0){
        vector <vector <int>> ans;
        return ans;
    }else if(n == 0 && k == 0){
        vector <vector <int>> ans = {{}};
        return ans;
    }else{  
        vector <vector <int>> ans;
        for (int i = current; i < 10; i++){
            vector <vector <int>> temp = helper(k - 1, n - i, i + 1);
            for (int j = 0; j < temp.size(); j++){
                temp[j].push_back(i);    
            }
            ans.insert(ans.begin(), temp.begin(), temp.end());
        }

        return ans;
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector <vector <int>> ans = helper(k, n, 1);

    return ans;
}

int main(){
    return 0;
}