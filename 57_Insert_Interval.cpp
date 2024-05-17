#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector <vector <int>> ans;

    int mx = 0;
    for (auto & it: intervals) {
        mx = max(mx, it[1]);
    }

    mx = max(mx, newInterval[1]);

    vector <int> sweeplineStart(mx + 5, 0);
    vector <int> sweeplineEnd(mx + 5, 0);

    for (auto & it: intervals) {
        sweeplineStart[it[0]]++;
        sweeplineEnd[it[1]]++;
    }

    sweeplineStart[newInterval[0]]++;
    sweeplineEnd[newInterval[1]]++;

    int current = 0;
    int start = -1;
    int end = -1;
    string state = "Entry";
    for (int i = 0; i < sweeplineStart.size(); i++) {
        current += sweeplineStart[i];
        if (state == "Entry") {
            if (current > 0 && sweeplineStart[i]) {
                start = i;
                state = "Entered";
            }
        }

        current -= sweeplineEnd[i];

        if (state == "Entered") {
            if (current == 0 && sweeplineEnd[i]) {
                end = i;
                state = "Entry";
                ans.push_back({start, end});
            }
        }
    }

    return ans;
}