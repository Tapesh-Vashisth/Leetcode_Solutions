#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> store;

int helper(string s, string t, vector <vector <int>> &dp, int x, int y) {
    if (x == 0 || y == 0) {
        return 1;
    }
    
    if (store[x][y] != -1) {
        return store[x][y];
    }

    int mx = max(dp[x - 1][y - 1] + (s[x - 1] == t[y - 1]), max(dp[x][y - 1], dp[x - 1][y]));

    int ret = 0;

    if (mx == dp[x - 1][y - 1] + 1 && s[x - 1] == t[y - 1]) {
        ret += helper(s, t, dp, x - 1, y - 1);
    } 

    if (mx == dp[x - 1][y]) {
        ret += helper(s, t, dp, x - 1, y);
    }

    if (mx == dp[x][y - 1]) {
        ret += helper(s, t, dp, x, y - 1);
    }

    store[x][y] = ret;

    return ret;
}

int numDistinct(string s, string t) {
    vector <vector <int>> dp (s.size() + 1, vector <int> (t.size() + 1,  0));


    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= t.size(); j++) {
            dp[i][j] = 0;        
        }
    }       

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            dp[i][j] = max(dp[i - 1][j - 1] + (s[i - 1] == t[j - 1]), max(dp[i - 1][j], dp[i][j - 1]));
            
        }
    }   

    int ans;

    if (dp[s.size()][t.size()] < t.size()) {
        ans = 0;
    } else {
        store = vector <vector <int>> (s.size() + 1, vector <int> (t.size() + 1, -1));
        ans = helper(s, t, dp, s.size(), t.size());
    }

    return ans;
}

int numDistinct(string s, string t) {
    vector <vector <unsigned long long>> store(s.size() + 1, vector <unsigned long long> (t.size() + 1, 0));
    for (int i = 0; i <= s.size(); i++) {
        store[i][0] = 1;
    }        

    for (int j = 1; j <= t.size(); j++) {
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] == t[j - 1]) {
                store[i][j] = store[i - 1][j - 1] + store[i - 1][j];
            } else {
                store[i][j] = store[i - 1][j];
            }
        }
    }


    return store[s.size()][t.size()];
}

int main() {
    return 0;
}