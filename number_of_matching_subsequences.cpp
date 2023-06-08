#include <iostream>
#include <vector>
using namespace std;

int numMatchingSubseq(string s, vector<string>& words) {
    vector <vector <int>> store(s.size(), vector <int> (26, -1));
    vector <int> jump(26, -1);
    jump[s[s.size() - 1] - 'a'] = s.size() - 1;
    for (int i = s.size() - 2; i >= 0; i--) {
        store[i] = store[i + 1];
        store[i][s[i + 1] - 'a'] = i + 1;
        jump[s[i] - 'a'] = i;
    }   

    int counter = 0;
    for (auto &it: words) {
        int current = jump[it[0] - 'a'];
        bool check = true;
        for (int i = 1; i < it.size(); i++) {
            if (current == -1) {
                check = false;
                break;
            } 

            current = store[current][it[i] - 'a']; 
        }

        if (current == -1) {
            check = false;
        }

        if (check) {
            counter++;
        }
    }

    return counter;
}

int main() {
    return 0;
}