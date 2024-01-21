#include <iostream>
#include <vector>
using namespace std;

bool checkPalindrome(string & s, int low, int high, vector <bool> & taken) {
    string str;
    for (int i = low; i <= high; i++) {
        if (taken[i]) {
            str.push_back(s[i]);
        }
    }

    if (str.size() > 1) {
        int l = 0;
        int h = str.size() - 1;

        while (l <= h) {
            if (str[l] != str[h]) {
                return false;
            }

            l++;
            h--;
        }

        return true;
    } else {
        return false;
    }
}

int main() {
    string s;

    int len = 0;
    vector <string> store;
    string hold;
    int n;
    while (cin >> s) {
        if (!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))) {
            n = stoi(s);
            break;
        }

        store.push_back(s);
        hold.push_back(tolower(s[0]));
        len++;
    }


    vector <bool> taken(len, true);
    int remain = len;
    for (int i = 0; i < len; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (checkPalindrome(hold, j, i, taken)) {
                taken[i] = false;
                remain--;    
                break;           
            }
        }
    }

    int index = 0;
    int pos = 0;
    while (remain > 1) {
        if (taken[index]) {
            if (pos == n - 1) {
                taken[index] = false;
                remain--;
                index = (index + 1) % len;
            } else {
                pos++;
                index = (index + 1) % len;
            }
        } else {
            index++;
        }
    }

    for (int i = 0; i < len; i++) {
        if (taken[i]) {
            cout << store[i] << endl;
            break;
        }
    }

    return 0;
}