#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    vector <vector <int>> dp (str1.size() + 1, vector <int> (str2.size() + 1,  0));

    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            dp[i][j] = max(dp[i - 1][j - 1] + (str1[i - 1] == str2[j - 1]), max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    string common = "";
    vector <int> index1;
    vector <int> index2;
    int x = str1.size();
    int y = str2.size();
    while (true) {
        if (x == 0 || y == 0) {
            break;
        }

        if (str1[x - 1] == str2[y - 1] && dp[x][y] == dp[x - 1][y - 1] + 1) {
            common.push_back(str1[x - 1]);
            index1.push_back(x);
            index2.push_back(y);
            x--;
            y--;
        } else {
            if (dp[x - 1][y] > dp[x][y - 1]) {
                x--;
            } else {
                y--;
            }
        }
    }

    reverse(common.begin(), common.end());
    reverse(index1.begin(), index1.end());
    reverse(index2.begin(), index2.end());

    for (int i = index1.size() - 1; i >= 0; i--) {
        cout << index1[i] << " ";
    }
    cout << endl;

    for (int i = index2.size() - 1; i >= 0; i--) {
        cout << index2[i] << " ";
    }
    cout << endl;

    string ans = "";
    int first = 0;
    int second = 0;
    int pointerOne = 0;
    int pointerTwo = 0;
    while (first < str1.size() && second < str2.size() && pointerOne < index1.size() && pointerTwo < index2.size()) {
        if (first < index1[pointerOne]) {
            ans.push_back(str1[first++]);
        } else if (second < index2[pointerTwo]) {
            ans.push_back(str2[second++]);
        } else {
            ans.push_back(str1[first++]);
            second++;
            pointerOne++;
            pointerTwo++;
        }
    }

    while (first < str1.size()) {
        ans.push_back(str1[first++]);
    }

    while (second < str2.size()) {
        ans.push_back(str2[second++]);
    }

    return ans;
}

int main() {
    return 0;
}