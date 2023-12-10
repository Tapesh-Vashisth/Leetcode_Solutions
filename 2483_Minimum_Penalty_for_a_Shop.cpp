#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bestClosingTime(string customers) {
    vector <int> before = {0};
    vector <int> after = {0};

    for (int i = 1; i <= customers.size(); i++) {
        before.push_back(before[before.size() - 1] + (customers[i - 1] == 'N' ? 1 : 0));
    }

    for (int i = customers.size() - 1; i >= 0; i--) {
        after.push_back(after[after.size() - 1] + (customers[i] == 'Y' ? 1 : 0));
    }
    reverse(after.begin(), after.end());

    int ans = 0;
    int hold = INT32_MAX;
    for (int i = 0; i < after.size(); i++) {
        if (before[i] + after[i] < hold) {
            hold = before[i] + after[i];
            ans = i;
        }
    }

    return ans;
}

int main() {
    return 0;
}