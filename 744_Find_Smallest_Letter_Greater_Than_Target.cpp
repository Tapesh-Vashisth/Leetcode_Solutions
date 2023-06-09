#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int pos = upper_bound(letters.begin(), letters.end(), target) - letters.begin();

    if (pos == letters.size()) {
        return letters[0];
    } else if (letters[pos] == target) {
        if (pos == letters.size() - 1) {
            return letters[0];
        } else {
            return letters[pos + 1];
        }
    } else {
        return letters[pos];
    }
}

int main() {
    return 0;
}