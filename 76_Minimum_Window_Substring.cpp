#include <iostream>
#include <vector>
#include <map>
using namespace std;

string minWindow(string s, string t) {
    map <char, int> store;  

    for (auto it: t) {
        store[it]++;
    }   


    int counter = 0;
    for (auto it: store) {
        counter++;
    }

    int low = 0;
    string ans = "";
    int ansLen = INT32_MAX;
    map <char, int> keep;
    for (int i = 0; i < s.size(); i++) {
        keep[s[i]]++;
        if (keep[s[i]] == store[s[i]]) {
            counter--;
        }

        if (counter == 0) {
            while (low <= i && counter == 0) {
                if (keep[s[low]] == store[s[low]]) {
                    counter++;
                }

                keep[s[low]]--;

                low++;
            }


            low--;
            keep[s[low]]++;
            if (keep[s[low]] == store[s[low]]) {
                counter--;
            }

            if (i - low + 1 < ansLen) {
                ansLen = (i - low + 1);
                ans = s.substr(low, (i - low + 1));
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}