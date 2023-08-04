#include <iostream>
#include <vector>
using namespace std;

vector <vector <string>> dp;

vector <string> helper(string & s, int index, vector <string> & wordDict) {
    if (index >= s.size()) {
        return {""};
    }

    if (dp[index][0] != "-1") {
        return dp[index];
    }

    vector <string> ret;
    for (int i = 0; i < wordDict.size(); i++) {
        if (wordDict[i].size() <= s.size() - index && s.substr(index, wordDict[i].size()) == wordDict[i]) {
            vector <string> hold = helper(s, index + wordDict[i].size(), wordDict);
            for (auto it: hold) {
                string temp = wordDict[i] + (it.size() > 0 ? " " : "");
                ret.push_back(it.insert(0, temp));
            }
        }
    }

    dp[index] = ret;

    return ret;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    dp = vector <vector <string>> (s.size(), {"-1"});
    vector <string> ans = helper(s, 0, wordDict);

    return ans;
}

int main() {
    return 0;
}