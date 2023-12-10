#include <iostream>
#include <algorithm>
using namespace std;

string convertToTitle(int columnNumber) {
    string ans = "";
    int hold = 1;
    while (columnNumber) {
        hold = columnNumber%26;
        columnNumber /= 26;
        if (hold == 0) {
            ans.push_back('Z');
            columnNumber--;
        } else {
            ans.push_back(('A') + hold - 1);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}