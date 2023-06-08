#include <iostream>
using namespace std;

int rearrangeCharacters(string s, string target) {
    int hash[26] = {0};
    for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < target.length(); j++){
            if (s[i] == target[j]){
                hash[s[i] - 'a']++;
                break;    
            }           
        }
    }
    int ans = 0;

    // for (int i = 0; i < 26; i++){
    //     cout << hash[i] << " ";
    // }
    // cout << endl;

    while (1){
        int decider = 1;
        for (int i = 0; i < target.length(); i++){
            if (hash[target[i] - 'a'] == 0){
                decider = 0;
                break;
            }else if(hash[target[i] - 'a'] != 0){
                hash[target[i] - 'a']--;
            }
        }

        if (decider){
            ans++;
        }else{
            break;
        }
    }

    return ans;
}

int main(){
    cout << rearrangeCharacters("zys", "adk") << endl;
    return 0;
}