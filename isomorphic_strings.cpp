#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t){
    unordered_map <char, char> m;
    int array[256] = {0};
    int used[256] = {0};
    for (int i = 0; i < s.size(); i++){
        unsigned char x = s[i];
        unsigned char y = t[i];
        if (array[x] == 0 && used[y] == 0){
            array[x] = 1;
            used[y] = 1;
            m[s[i]] = t[i];
        }else if (array[x] == 0 && used[y] == 1){
            return false;
        }else{
            if (t[i] != m[s[i]]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    return 0;
}