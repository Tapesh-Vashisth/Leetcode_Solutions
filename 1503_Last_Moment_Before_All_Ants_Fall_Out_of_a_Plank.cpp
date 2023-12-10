#include <iostream>
#include <vector>
using namespace std;

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int ans = 0;
    for (auto it: right) {
        ans = max(ans, n - it);
    }        

    for (auto it: left) {
        ans = max(ans, it);
    }

    return ans;
}

int main() {
    return 0;
}