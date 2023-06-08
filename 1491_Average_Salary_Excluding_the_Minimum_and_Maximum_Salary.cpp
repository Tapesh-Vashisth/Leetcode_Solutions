#include <iostream>
#include <vector>
using namespace std;

double average(vector<int>& salary) {
    double mn = INT32_MAX;
    double mx = INT32_MIN;
    double total = 0;

    for (auto & it: salary) {
        mn = min(mn, (double)it);
        mx = max(mx, (double)it);
        total += it;
    }

    return ((total - (mn + mx))/(salary.size() - 2.0));
}

int main() {
    return 0;
}