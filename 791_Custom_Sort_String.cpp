#include <iostream>
#include <vector>
using namespace std;

string customSortString(string order, string s) {
    vector <int> back(26, -1);
    vector <int> forward(26, -1);

    for (int i = 1; i < order.size(); i++) {
        back[order[i] - 'a'] = order[i - 1] - 'a';
        forward[order[i - 1] - 'a'] = order[i] - 'a';
    }        

    vector <int> freq(26, 0);

    for (auto it: s) {
        freq[it - 'a']++;
    }

    string ans = "";

    for (int i = 0; i < 26; i++) {
        if (back[i] == -1) {
            int hold = i;

            while (hold != -1) {
                while (freq[hold]) {
                    ans.push_back(hold + 'a');
                    freq[hold]--;
                }

                hold = forward[hold];
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}