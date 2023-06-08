#include <iostream>
#include <vector>
using namespace std;

int longestPalindrome(vector<string>& words) {
    vector <vector <int>> mainStore(26, vector <int> (26, 0));
    int len = words.size();
    for (int i = 0; i < len; i++){
        int x = words[i][0] - 'a';
        int y = words[i][1] - 'a';
        mainStore[x][y]++;
    }

    int ans = 0;
    int control = 0;
    for (int i = 0; i < 26; i++){
        if (mainStore[i][i] % 2 == 1 && control == 0){
            ans += mainStore[i][i];
            control++;
        }else{
            int holder = (mainStore[i][i] / 2) * 2;
            ans += holder;
        }
    }

    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            if (i != j){
                int first = mainStore[i][j];
                int second = mainStore[j][i];
                int add = min(first, second);
                ans += add;
            }
        }
    }
    
    return ans;
}

int main(){
    return 0;
}








