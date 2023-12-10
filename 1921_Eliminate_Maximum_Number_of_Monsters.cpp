#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    priority_queue <int, vector<int>, greater<int>> times;

    for (int i = 0; i < dist.size(); i++) {
        times.push((dist[i] + speed[i] - 1)/speed[i]);
    }

    int current = 1;
    times.pop();
    while (!times.empty()) {
        int hold = times.top();
        times.pop();

        if (current >= hold) {
            return current;
        }

        current += 1;
    }

    return current;
}

int main() {
    return 0;
}