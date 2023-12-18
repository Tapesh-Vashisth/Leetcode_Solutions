#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {
    vector <int> hash(26, 0);

    for (auto it: s) {
        hash[it - 'a']++;
    }

    for (auto it: t) {
        if (hash[it - 'a'] <= 0) {
            return false;
        }

        hash[it - 'a']--;
    }

    for (auto it: hash) {
        if (it != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    return 0;
}