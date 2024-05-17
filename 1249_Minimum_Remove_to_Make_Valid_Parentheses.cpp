#include <iostream>
#include <vector>
using namespace std;

string minRemoveToMakeValid(string s) {
    vector <bool> keep(s.size(), true);

    int current = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            current++;
        } else if (s[i] == ')') {
            current--;
        }

        if (current < 0) {
            keep[i] = false;
            current = 0;
        }
    }

    string hold = "";
    for (int i = 0; i < s.size(); i++) {
        if (keep[i]) {
            hold.push_back(s[i]);
        }
    }

    vector <int> store;
    current = 0;

    for (int i = 0; i < hold.size(); i++) {
        if (hold[i] == '(') {
            current++;
        } else if (hold[i] == ')') {
            current--;
        }

        store.push_back(current);
    }

    vector <int> hash(hold.size() + 1, -1);

    keep = vector <bool> (hold.size(), true);

    for (int i = hold.size() - 1; i >= 0; i--) {
        if (hold[i] == '(') {
            if (hash[store[i] - 1] == -1) {
                keep[i] = false;
            }
        } else if (hold[i] == ')') {
            if (hash[store[i]] == -1) {
                hash[store[i]] = i;
            } 
        }
    }
    
    string ans;
    for (int i = 0; i < hold.size(); i++) {
        if (keep[i]) {
            ans.push_back(hold[i]);
        }
    }

    return ans;
}

int main() {
    return 0;
}