#include <iostream>
#include <vector>
using namespace std;

int countPalindromicSubsequence(string s) {
    vector <int> right(26, 0);
    vector <int> left(26, 0);

    vector <vector <bool>> hash(26, vector <bool> (26, false));

    for (auto it: s) {
        right[it - 'a']++;
    }        

    int ans = 0;
    for (auto it: s) {
        right[it - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (left[i] > 0 && right[i] > 0 && hash[it - 'a'][i] == false) {
                hash[it - 'a'][i] = true;
                ans++;
            }
        }

        left[it - 'a']++;
    }


    return ans;
}

int main() {
    return 0;
}