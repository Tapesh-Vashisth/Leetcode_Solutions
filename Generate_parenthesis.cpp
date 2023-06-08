#include <iostream>
#include <vector>
using namespace std;

vector <string> ans;

void helper(string process, int n, int now, int opened){
    // cout << process << endl;
    if (now == n && opened == 0){
        ans.push_back(process);
    }else if(opened < 0){
        ;
    }else if(now < n){
        helper(process + '(', n, now + 1, opened + 1);
        helper(process + ')', n, now + 1, opened - 1);
    }   
}

vector<string> generateParenthesis(int n){
    cout << "hi" << endl;
    helper("", 2*n, 0, 0);
    return ans;
}

int main(){
    vector <string> ans;
    ans = generateParenthesis(6);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}