#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    } else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }

    return 0;
}

bool halvesAreAlike(string s) {
    int first = 0;

    for (int i = 0; i < s.size()/2; i++) {
        int check = isVowel(s[i]);

        if (check == 1 || check == 2) {
            first++;
        }
    }

    for (int i = s.size()/2; i < s.size(); i++) {
        int check = isVowel(s[i]);

        if (check == 1 || check == 2) {
            first--;
        }
    }

    return first == 0;
}

int main() {
    return 0;
}