#include <iostream>
#include <vector>
using namespace std;

bool check(string & str) {
    int low = 0;
    int high = str.size() - 1;

    while (low < high) {
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}

string firstPalindrome(vector<string>& words) {
    for (auto & it: words) {
        if (check(it)) {
            return it;
        }
    }        

    return "";
}

int main() {
    return 0;
}