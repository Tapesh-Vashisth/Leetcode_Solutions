#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> dp;

bool helper(string & s1, string & s2, string & s3, int index1, int index2) {
    int index3 = index1 + index2;

    if (index1 >= s1.size() && index2 >= s2.size() && s3.size() == index3) {
        return true;
    } else if (index3 >= s3.size()) {
        return false;
    }

    if (dp[index1][index2] != -1) {
        return dp[index1][index2];
    }

    bool ret = false;
    if (index1 < s1.size() && s1[index1] == s3[index3]) {
        ret = ret || helper(s1, s2, s3, index1 + 1, index2);
    }   

    if (index2 < s2.size() && s2[index2] == s3[index3]) {
        ret = ret || helper(s1, s2, s3, index1, index2 + 1);
    }   

    dp[index1][index2] = ret;

    return ret;  
}

bool isInterleave(string s1, string s2, string s3) {
    dp = vector <vector <int>> (s1.size() + 1, vector <int> (s2.size() + 1, -1));
    return helper(s1, s2, s3, 0, 0);
}

int main() {
    return 0;
}