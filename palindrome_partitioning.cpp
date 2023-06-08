#include <iostream>
#include <vector>
using namespace std;

bool check(string s, int start, int end){
    for (int i = 0; i < (end - start)/2; i++){
        if (s[i] != s[end - i - 1]){
            return false;
        }
    }

    return true;
}

vector<vector<string>> partition_helper(string s, int current){
    if (current > s.size() - 1){
        vector <vector <string>> ans;
        return ans;
    }else{
        vector <vector <string>> ans;
        for (int i = current + 1; i <= s.size(); i++){
            if (check(s, current, i)){
                vector <vector <string>> temp = partition_helper(s, i);
                for (int i = 0; i < temp.size(); i++){
                    temp[i].push_back(s.substr(current, i - current));
                }

                ans.insert(ans.begin(), temp.begin(), temp.end());
            }
        }
        return ans;
    }

}

vector<vector<string>> partition(string s){
    vector <vector <string>> ans;
    ans = partition_helper(s, 0);
    return ans;
}

int main(){
    return 0;
}