#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

string removeDuplicateLetters(string s) {
    vector <vector <int>> store(s.size());
    vector <vector <int>> pos(26);
    vector <int> hash (26, 0);
    set <char> uniq;
    for (int i = s.size() - 1; i >= 0; i--) {
        pos[s[(s.size() - 1) - i] - 'a'].push_back((s.size() - 1) - i);
        store[i] = hash;
        uniq.insert(s[i]);
        hash[s[i] - 'a']++;
    }


    int start = 0;
    vector <bool> used(26, false);

    int distinct = uniq.size();
    string ans;
    for (int i = 0; i < distinct; i++) {
        for (int j = 0; j < 26; j++) {
            if (used[j] == false) {
                int hold = lower_bound(pos[j].begin(), pos[j].end(), start) - pos[j].begin();
                if (hold < pos[j].size()) {
                    bool decider = true;
                    used[j] = true;
                    for (int k = 0; k < 26; k++) {
                        if (uniq.count('a' + k)) {
                            if (used[k] == false) {
                                if (store[pos[j][hold]][k] == 0) {
                                    decider = false;
                                    break;
                                }
                            }
                        }
                    }

                    if (decider) {
                        uniq.erase('a' + j);
                        ans.push_back('a' + j);
                        start = pos[j][hold] + 1;
                        break;     
                    } else {
                        used[j] = false;
                    }
                } 
            }
        }        
    }

    return ans;
}

int main() {
    return 0;
}