#include <iostream>
#include <vector>
using namespace std;

string maximumOddBinaryNumber(string s) {
    string ans(s.size(), '0');

    int ones = 0;
    for (auto it: s) {
        if (it == '1') {
            ones++;
        }
    }        

    if (ones) {
        ans[ans.size() - 1] = '1';
        ones--;
    }

    int index = 0;
    while (ones) {
        ans[index] = '1';
        index++;
        ones--;
    }

    return ans;
}

int main() {
    return 0;
}