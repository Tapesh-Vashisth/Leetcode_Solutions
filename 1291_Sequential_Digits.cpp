#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sequentialDigits(int low, int high) {
    vector <int> ans;
    for (int start = 1; start <= 9; start++) {
        string hold;
        int current = start;
        hold.push_back(start + '0');

        while (stoll(hold) <= high && current <= 9) {
            current++;

            if (stoll(hold) >= low) {
                ans.push_back(stoi(hold));
            }

            if (current <= 9) {
                hold.push_back(current + '0');
            }
        }
    }        

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {

    return 0;
}