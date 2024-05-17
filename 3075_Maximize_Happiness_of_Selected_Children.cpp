#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long maximumHappinessSum(vector<int> & happiness, int k) {
    priority_queue <int> store;

    for (auto it: happiness) {
        store.push(it);
    }

    long long ans = 0;
    int round = 0;
    while (k && !store.empty()) {
        int hold = store.top();
        store.pop();

        ans += (hold - round > 0 ? (hold - round): 0);

        k--;
        round++;
    }

    return ans;
}

int main() {
    return 0;
}