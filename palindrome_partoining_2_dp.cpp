#include <iostream>
using namespace std;

bool check(string s, int start, int end){
    
    for (int i = start; i < start + (end - start)/2; i++){
        if (s[i] != s[end - (i - start) - 1]){
            return false;
        }
    }
    return true;
}

int helper(string s, int start, int current){
    if (current == s.size()){
        return 0;
    }
    int ans;
    if (check(s, start, current + 1)){
        int first = helper(s, start, current + 1);
        int second = helper(s, current + 1, current + 1);
        ans = min(first, second);
    }else{
        ans = helper(s, start, current + 1);
    }

    return ans + 1;
}

int minCut(string s){
    return helper(s, 0, 0);
}

int main(){
    return 0;
}