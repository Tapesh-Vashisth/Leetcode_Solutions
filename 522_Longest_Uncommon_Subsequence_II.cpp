#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    static bool comparator(string & s1, string & s2) {
        if(s1.size() >= s2.size()) {
            return false;
        }

        return true;
    }

    bool check(string & s1, string & s2) {
        vector <vector <bool>> dp (s1.size() + 1, vector <bool> (s2.size() + 1, false));

        // base 
        for (int i = 0; i <= s2.size(); i++) {
            dp[0][i] = true;
        }

        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = (dp[i - 1][j] & dp[i][j - 1]);
                }
            }
        }

        return dp[s1.size()][s2.size()];
    }

    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), comparator);


        unordered_map <string, bool> mapping;

        int mx = INT32_MIN;
        
        for (int i = 0; i < strs.size(); i++) {
            if (mapping[strs[i]]) {
                continue;    
            }

            bool decider = true;

            for (int j = i + 1; j < strs.size(); j++) {
                if (check(strs[i], strs[j])) {
                    decider = false;
                    break;
                }                
            }

            if (decider) {
                mx = max(mx, (int)strs[i].size());
            }

            mapping[strs[i]] = true;
        }

        return mx == INT32_MIN ? -1: mx;
    }
};

int main() {
    return 0;
}