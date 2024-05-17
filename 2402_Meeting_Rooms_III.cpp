#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());

    priority_queue <pair <long long, long long>, vector<pair <long long, long long>>, greater<pair <long long, long long>>> endStore;
    priority_queue <int, vector<int>, greater<int>> slots;

    for (int i = 0; i < n; i++) {
        slots.push(i);
    }

    vector <int> store(n, 0);

    long long timing = 0;
    for (int i = 0; i < meetings.size(); i++) {
        while (!endStore.empty() && endStore.top().first <= meetings[i][0]) {
            slots.push(endStore.top().second);
            endStore.pop();
        }

        if (slots.empty()) {
            pair <long long, long long> hold = endStore.top();
            timing = hold.first;
            endStore.pop();

            slots.push(hold.second);
        }

        int slot = slots.top();
        slots.pop();

        store[slot]++;
        endStore.push({max(timing + (meetings[i][1] - meetings[i][0]), (long long)meetings[i][1]), slot});
    }

    int mx = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (store[i] > mx) {
            index = i;
            mx = store[i];
        }
    }

    return index;
}

int main() {
    return 0;
}