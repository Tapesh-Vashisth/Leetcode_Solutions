#include <iostream>
#include <vector>
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int mn = 0;
    int mx = 0;

    int ans = 0;
    int current = 0;
    for (auto it: nums) {
        current += it;
        ans = max(ans, max(abs(current - mn), abs(current - mx)));

        mn = min(mn, current);
        mx = max(mx, current);
    }        


    return ans;
}

int main() {
    return 0;
}