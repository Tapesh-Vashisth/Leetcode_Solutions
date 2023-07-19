#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    int ans = 0;
    int endpoint = -1e5;


    for (auto it: intervals) {
        if (it[0] >= endpoint) {
            endpoint = it[1];
        } else {
            if (it[1] < endpoint) {
                endpoint = it[1];
            }

            ans++;
        }
    }

    return ans;        
}


int main() {

    return 0;
}