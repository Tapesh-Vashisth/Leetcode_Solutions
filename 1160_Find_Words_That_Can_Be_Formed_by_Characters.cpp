#include <iostream>
#include <vector>
using namespace std;

int countCharacters(vector<string>& words, string chars) {
    int ans = 0;

    vector <int> hash(26, 0);
    for (auto it: chars) {
        hash[it - 'a']++;
    }


    for (auto it: words) {
        vector <int> temp(26, 0);

        bool decider = false;
        for (auto c: it) {
            temp[c - 'a']++;

            if (temp[c - 'a'] > hash[c - 'a']) {
                decider = true;
                break;
            }
        }

        if (!decider) {
            ans += it.size();
        }
    }        

    return ans;
}

int main() {
    return 0;
}