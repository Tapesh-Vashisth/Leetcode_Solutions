#include <iostream>
#include <vector>
using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string first = "";
    string second = "";

    for (auto it: word1) {
        first.append(it);
    }

    for (auto it: word2) {
        second.append(it);
    }

    return first == second;
}

int main() {
    return 0;
}