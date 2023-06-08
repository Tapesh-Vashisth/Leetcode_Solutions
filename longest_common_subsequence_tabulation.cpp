#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestsubsequence(vector <vector <int>>& table, int x, int y, string temp, string text1, string text2){
    if (x == 0 && y == 0){
        return temp;
    }else{
        if (x > 0 && y > 0){
            if (text1[x - 1] == text2[y - 1]){
                temp.push_back(text1[x - 1]);
                return longestsubsequence(table, x - 1, y - 1, temp, text1, text2);
            }else{
                if (table[x - 1][y] >= table[x][y - 1]){
                    return longestsubsequence(table, x - 1, y, temp, text1, text2);
                }else{
                    return longestsubsequence(table, x, y - 1, temp, text1, text2);
                }
            }
        }else if (x == 0){
            return longestsubsequence(table, x, y - 1, temp, text1, text2);
        }else{
            return longestsubsequence(table, x - 1, y, temp, text1, text2);
        }
    }
    
    return temp;
}

int longestCommonSubsequence(string text1, string text2){
    int n = text1.size();
    int m = text2.size();
    vector <vector <int>> table(n + 1, vector <int> (m + 1, 0));
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            if (text1[i - 1] == text2[j - 1]){
                table[i][j] += table[i - 1][j - 1] + 1;
            }else{
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }


    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < m + 1; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    cout << longestsubsequence(table, n, m, "", text1, text2) << endl;

    return table[n][m];
}

int main(){
    cout << longestCommonSubsequence("abcdefg", "bdfz");
    return 0;
}