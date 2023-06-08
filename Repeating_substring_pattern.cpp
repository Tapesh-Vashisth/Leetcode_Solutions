#include <iostream>
#include <set>
using namespace std;

bool repeatedSubstringPattern(string s){
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++){
        hash[s[i] - 'a']++;
    }    

    set <int> store;
    int len = 0;
    for (int i = 0; i < 26; i++){
        if (hash[i] != 0){
            store.insert(hash[i]);
            len++;
        }
    }


    set <int> :: iterator it = store.begin();

    if (*it <= 1){
        return false;
    }else{
        int xd = *it;
        for (int j = len; j <= s.size()/2; j++){
            int small_decider = 1;
            string check = s.substr(0, j);
            for (int i = 0; i < s.size(); i = i + j){
                if (check.compare(s.substr(i, j)) == 0){
                    ;
                }else{
                    small_decider = 0;
                    break;
                }
            }
            if (small_decider == 1){
                return true;
            }
        }
    }


    return false;
}

int main(){
    cout << repeatedSubstringPattern("abaababaab") << endl;
    return 0;
}