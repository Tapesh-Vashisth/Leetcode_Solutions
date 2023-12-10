#include <iostream>
#include <vector>
using namespace std;

char findTheDifference(string s, string t) {
    vector <int> hash(26, 0);
    for (auto & it: s) {
        hash[it - 'a']++;
    }

    for (auto & it: t) {
        hash[it - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (hash[i]) {
            return 'a' + i;
        }
    }

    return 'a';
}

int main() {
    return 0;
}