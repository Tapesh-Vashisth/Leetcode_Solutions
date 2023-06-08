#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countbits(int x){
    int count = 0;

    while (x){
        x = x & (x - 1);
        count++;
    }

    return count;
}

vector<int> sortByBits(vector<int>& arr){
    vector <pair<int, int>> ans;
    for (int i = 0; i < arr.size(); i++){
        pair <int, int> temp;
        temp.first = countbits(arr[i]);
        temp.second = arr[i];
        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    
    vector <int> ans_main;
    for (int i = 0; i < ans.size(); i++){
        ans_main.push_back(ans[i].second);
    }
    return ans_main;
}

int main(){
    vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    sortByBits(v);
    return 0;
}