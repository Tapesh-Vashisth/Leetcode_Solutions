#include <iostream>
#include <vector>
using namespace std;

int removeAlmostEqualCharacters(string word) {
    bool change = false;
    int ans = 0;
    for (int i = 1; i < word.size(); i++) {
        if (abs(word[i] - word[i - 1]) <= 1) {
            if (change == false) {
                ans++;
                change = true;                
            } else {
                change = false;
            }
        } else {
            change = false;
        }
    }
    
    return ans;
}

int main() {
    return 0;
}