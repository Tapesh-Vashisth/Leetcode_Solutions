#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string makeGood(string s) {
    vector <bool> hash(s.size(), true);        

    int current = 1;
    int prev = 0;

    while (current < s.size()) {
        if (prev >= 0 && ((islower(s[prev]) && isupper(s[current]) && tolower(s[prev]) == tolower(s[current])) || (islower(s[current]) && isupper(s[prev]) && tolower(s[current]) == tolower(s[prev])))) {
            hash[current] = false;
            hash[prev] = false;
            
            while (prev >= 0 && hash[prev] == false) {
                prev--;
            }
        } else {
            prev = current;
        }

        current++;
    }   

    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        if (hash[i]) {
            ans.push_back(s[i]);
        }
    }

    return ans;
}

int main() {
    return 0;
}