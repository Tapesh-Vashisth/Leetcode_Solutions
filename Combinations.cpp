#include <iostream>
#include <vector>
using namespace std;

vector <pair<pair<int, int>, vector <vector<int>>>> storage;

vector <vector <int>> helper(int n, int k, int offset){
    if (k == 0 || offset > n){
        return vector <vector <int>> {{}};
    }else{
        for (int i = 0; i < storage.size(); i++){
            if (storage[i].first.first == k && storage[i].first.second == offset){
                // cout << "hi" << endl;
                return storage[i].second;
            }
        }

        vector <vector <int>> ans;
        // included
        vector <vector <int>> temp = helper(n, k - 1, offset + 1);
        for (int i = 0; i < temp.size(); i++){
            temp[i].push_back(offset);
            if (temp[i].size() == k){
                ans.push_back(temp[i]);
            }
        }

        // not included 
        temp = helper(n, k, offset + 1);
        for (int i = 0; i < temp.size(); i++){
            if (temp[i].size() == k){
                ans.push_back(temp[i]);
            } 
        }
        pair<pair <int, int>, vector<vector<int>>> xd = {{k, offset}, ans};
        storage.insert(storage.begin(), xd);
        
        return ans;
    }
}

vector<vector<int>> combine(int n, int k){
    storage.clear();
    return helper(n, k, 1);
}

int main(){
    vector <vector <int>> holder = combine(20, 16);
    for (int i = 0; i < holder.size(); i++){
        for (int j = 0; j < holder[0].size(); j++){
            cout << holder[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}