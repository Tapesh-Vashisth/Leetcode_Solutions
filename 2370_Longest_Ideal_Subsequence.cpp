#include <iostream>
#include <vector>
using namespace std;

int longestIdealString(string s, int k) {
    vector <int> dp(s.size(), 1);
    
    int ans = 1;
    vector <int> mapping(26, -1);
    for (int i = s.size() - 1; i >= 0; i--) {
        // check for range k 
        int center = s[i] - 'a';
        
        int move = 0;
        // ahead 
        while (center + move < 26 && move <= k) {
            if (mapping[center + move] != -1) {
                dp[i] = max(dp[i], 1 + dp[mapping[center + move]]);
            }
            move++;
        }

        move = 0;
        // behind 
        while (center - move >= 0 && move <= k) {
            if (mapping[center - move] != -1) {
                dp[i] = max(dp[i], 1 + dp[mapping[center - move]]);
            }
            move++;
        }

        ans = max(ans, dp[i]);

        mapping[s[i] - 'a'] = i;
    }        

    return ans;
}

int main() {
    return 0;
}