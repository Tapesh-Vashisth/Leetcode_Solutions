#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int instance = 2*numRows - 2;
    int n = s.size();

    int count = n/instance;       
    int remain = n%instance;
    int add = 0;
    if (remain > 0) {
        add++;
        if (remain/numRows) {
            add += (remain%numRows);
        }
    }

    int total = count * (numRows - 1) + add;

    vector <vector <string>> store(numRows, vector <string> (total, ""));

    // 0 -> down 
    // 1 -> diagonal 
    int direction = 0;
    int x = 0;
    int y = 0;
    int pointer = 0;
    while (pointer < n) {
        if (direction == 0) {
            store[x][y] = s[pointer];
            x++;
            if (x == numRows) {
                direction = 1;
                y++;
                x -= 2;
            }
        } else if (direction == 1) {
            store[x][y] = s[pointer];
            x--;
            y++;
            if (x == -1) {
                direction = 0;
                x += 2;
                y--;
            }
        }

        pointer++;
    }
    cout << "hm" << endl;


    string ans = "";
    for (int i = 0; i < store.size(); i++) {
        for (int j = 0; j < store[i].size(); j++) {
            if (store[i][j] != "") {
                ans.append(store[i][j]);
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}