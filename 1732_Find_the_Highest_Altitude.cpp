#include <iostream>
#include <vector>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int ans = 0;

    int hold = 0;

    for (int i = 0; i < gain.size(); i++) {
        hold += gain[i];
        ans = max(ans, hold);
    }

    return ans;
}

int main() {

    return 0;
}