#include <iostream>
#include <algorithm>
using namespace std;

string reversePrefix(string word, char ch) {
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == ch) {
            reverse(word.begin(), word.begin() + i + 1);
            break;
        }
    }        

    return word;
}

int main() {
    return 0;
}