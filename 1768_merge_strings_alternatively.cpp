#include <iostream>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string ans = "";
    int first = 0;
    int second = 0;
    int counter = 0;
    while (first < word1.size() && second < word2.size()) {
        if (counter % 2 == 0) {
            ans.push_back(word1[first++]);
        } else {
            ans.push_back(word2[second++]);
        }
        counter++;
    }

    while (first < word1.size()) {
        ans.push_back(word1[first++]);
    }  

    while (second < word2.size()) {
        ans.push_back(word2[second++]);
    }      

    return ans;
}

int main() {

    return 0;
}