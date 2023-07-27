#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int n, vector <int> & batteries, long long limit) {
    long long pile = 0;
    long long up = 0;
    long long index = 0;
    while (pile < n && index < batteries.size()) {
        long long prev = up;
        up += batteries[index];
        index++;

        if (up >= limit) {
            pile++;
            long long extra = up - limit;
            up = min(prev, extra);
        } else {
            ;
        }
    }

    if (pile >= n) {
        return true;
    }

    return false;
}

long long maxRunTime(int n, vector<int>& batteries) {
    long long total = 0;
    for (auto it: batteries) {
        total += it;
    }

    long long low = 0;
    long long high = total/n;

    long long mx = 0;
    sort(batteries.begin(), batteries.end(), greater<int> ());
    while (low <= high) {
        long long mid = low + (high - low)/2;

        if (check(n, batteries, mid)) {
            mx = max(mx, mid);            
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return mx;
}

int main() {
    return 0;
}