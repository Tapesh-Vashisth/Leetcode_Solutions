#include <iostream>
#include <vector>
using namespace std;

bool buddyStrings(string s, string goal) {
    if (s.size() == goal.size()) {
        vector <int> discrep;

        vector <int> hash(26, 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                discrep.push_back(i);
            }
            hash[s[i] - 'a']++;
        }

        if (discrep.size() == 2) {
            if (s[discrep[0]] == goal[discrep[1]] && s[discrep[1]] == goal[discrep[0]]) {
                return true;
            } else {
                return false;
            }
        } else if (discrep.size() == 0) {
            for (auto it: hash) {
                if (it > 1) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    return 0;
}