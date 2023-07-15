#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end());

    priority_queue <int, vector<int>, greater<int>> store;

    int index = 0;
    int pointer = 1;
    int counter = 0;
    int ans = 0;
    while (index < events.size() || !store.empty()) {
        while (index < events.size() && events[index][0] == pointer) {
            store.push(events[index][1]);
            counter++;
            index++;
        }

        if (counter > 0) {
            counter--;
            ans++;
            store.pop();
        }

        while (counter > 0 && store.top() == pointer) {
            counter--;
            store.pop();
        }

        pointer++;
    }

    return ans;
}

int main() {
    return 0;
}