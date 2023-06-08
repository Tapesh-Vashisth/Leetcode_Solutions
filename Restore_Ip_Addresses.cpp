#include <iostream>
#include <vector>
using namespace std;

vector <string> ans;

void helper(string s, int index, int moves, string construct) {
    if (moves == 4 && index == s.size()) {
        ans.push_back(construct);
    } else if (moves >= 4 || index > s.size()) {
        ;
    } else if (moves < 4) {
        string imp = construct;
        for (int i = 1; i <= 3; i++) {
            string sub = s.substr(index, i);
            cout << sub << endl;
            if (sub != "" && (sub[0] != '0' || sub == "0")) {
                int hold = stoi(s.substr(index, i));
                if (hold <= 255) {
                    construct.append(sub + ".");
                    helper(s, index + i, moves + 1, construct);
                    construct = imp;
                }
            }
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    ans.clear();
    helper(s, 0, 0, "");
    for (int i = 0; i < ans.size(); i++) {
        ans[i].pop_back();
    }
    return ans;    
}

int main() {
    return 0;
}