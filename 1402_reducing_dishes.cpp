#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());

    int hold = 0;
    int ans = 0;
    while (satisfaction[hold] < 0) {
        int temp = 0;
        for (int i = hold; i < satisfaction.size(); i++) {
            temp += (i + 1) * satisfaction[i];
        }

        ans = max(ans, temp);
        hold++;
    }

    return ans;
}

int main() {
    return 0;
}