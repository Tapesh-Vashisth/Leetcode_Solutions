#include <iostream>
using namespace std;

bool isSubsequence(string s, string t){
    int first = 0;
    for (int i = 0; i < t.size() && first != s.size(); i++){
        if (s[first] == t[i]){
            first++;
        }
    }

    if (first == s.size()){
        return true;
    }else{
        return false;
    }
}

int main(){
    return 0;
}