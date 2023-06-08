#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    vector <int> ans;
    vector <int> store;

    for (int i = 0; i < obstacles.size(); i++) {
        int pos = upper_bound(store.begin(), store.end(), obstacles[i]) - store.begin();

        if (pos == store.size() || (pos == store.size() - 1 && obstacles[i] == store[pos])) {
            store.push_back(obstacles[i]);
            ans.push_back(pos + 1);
        } else if (obstacles[i] == store[pos]) {
            store[pos + 1] = obstacles[i];
            ans.push_back(pos + 1);
        } else {
            store[pos] = obstacles[i];
            ans.push_back(pos + 1);
        }
    }

    return ans;
}

int main() {
    return 0;
}