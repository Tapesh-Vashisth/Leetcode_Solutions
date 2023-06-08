#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isMatch(string s, string p) {
    vector <string> pattern;

    for (int i = p.size() - 1; i >= 0; i--) {
        if (p[i] == '*') {
            pattern.push_back(p.substr(i - 1, 2));
            i--;
        } else {
            string temp;
            temp.push_back(p[i]);
            pattern.push_back(temp);
        }
    }

    reverse(pattern.begin(), pattern.end());

    vector <vector <bool>> dp(s.size() + 1, vector <bool> (pattern.size() + 1, false));

    dp[0][0] = true;

    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i].size() != 2) {
            break;
        }         

        dp[0][i + 1] = true;   
    }

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= pattern.size(); j++) {
            if (pattern[j - 1].size() == 2) {

                bool first = false;
                bool second = false;

                if (pattern[j - 1][0] == '.' || (pattern[j - 1][0] == s[i - 1])) {
                    first = dp[i - 1][j - 1];
                    second = dp[i - 1][j];
                }

                bool third = dp[i][j - 1];

                dp[i][j] = (first || second || third);
            } else if (pattern[j - 1] == ".") {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                if (s[i - 1] == pattern[j - 1][0]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }


    return dp[s.size()][pattern.size()];
}

int main() {
    return 0;
}