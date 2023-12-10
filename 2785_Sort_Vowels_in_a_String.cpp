#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }

    return false;
}

string sortVowels(string s) {
    priority_queue <char, vector<char>, greater<char>> store;

    for (auto it: s) {
        if (isVowel(it)) {
            store.push(it);
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i])) {
            s[i] = store.top();
            store.pop();
        }
    }

    return s;
}

int main() {
    return 0;
}