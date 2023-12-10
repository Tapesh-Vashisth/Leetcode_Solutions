#include <iostream>
#include <vector>
using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    int current = 0;

    vector <string> ans;
    for (int i = 1; i <= n; i++) {
        if (current < target.size()) {
            if (i == target[current]) {
                ans.push_back("Push");
                current++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        } else {
            break;
        }
    }

    return ans;
}

int main() {
    return 0;
}