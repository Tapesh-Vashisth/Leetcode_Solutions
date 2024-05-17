#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int helper(vector<int> machines) {
    priority_queue <pair <int, int>> right;
    priority_queue <pair <int, int>> left;


    long long total = 0;
    int index = 0;
    for (auto it: machines) {
        total += it;
        right.push({it, index});
        index++;
    }

    if (total % machines.size() != 0) {
        return -1;
    }

    int margin = total/machines.size();

    int ans = 0;

    for (int i = 0; i < machines.size(); i++) {
        while (!right.empty() && !left.empty() && margin - machines[i] > 0) {
            if (right.top().second <= i) {
                right.pop();
                continue;
            }

            if (left.top().first > margin && right.top().first > margin) {
                if (margin - machines[i] > 1) {
                    machines[i] += 2;
                    ans += 1;
                    int leftIndex = left.top().second;
                    int rightIndex = right.top().second;
                    machines[leftIndex]--;
                    machines[rightIndex]--;
                    left.pop();
                    right.pop();
                    left.push({machines[leftIndex], leftIndex});
                    right.push({machines[rightIndex], rightIndex});
                } else {
                    if (left.top().first > right.top().first) {
                        machines[i]++;
                        ans += 1;
                        int leftIndex = left.top().second;
                        machines[leftIndex]--;
                        left.pop();
                        left.push({machines[leftIndex], leftIndex});        
                    } else {
                        machines[i]++;
                        ans += 1;
                        int rightIndex = right.top().second;
                        machines[rightIndex]--;
                        right.pop();
                        right.push({machines[rightIndex], rightIndex});
                    }
                }
            } else {
                break;
            }
        }

        while (margin - machines[i] > 0 && !left.empty()) {
            if (left.top().first > margin) {
                machines[i]++;
                ans += 1;
                int leftIndex = left.top().second;
                machines[leftIndex]--;
                left.pop();
                left.push({machines[leftIndex], leftIndex});
            } else {
                left.pop();
            }
        } 

        while (margin - machines[i] > 0 && !right.empty()) {
            if (right.top().second <= i) {
                right.pop();
                continue;
            }

            if (right.top().first > margin) {
                machines[i]++;
                ans += 1;
                int rightIndex = right.top().second;
                machines[rightIndex]--;
                right.pop();
                right.push({machines[rightIndex], rightIndex});
            } else {
                right.pop();
            }
        }

        left.push({machines[i], i});

        cout << ans << endl;
        for (auto it: machines) {
            cout << it << " ";
        }
        cout << endl;
    }

    return ans;
}

int findMinMoves(vector<int>& machines) {
    long long total = 0;
    for (auto it: machines) {
        total += it;
    }

    if (total % machines.size() != 0) {
        return -1;
    }

    int margin = total % machines.size();

    int prev = 0;
    int current = 0;
    int ans = INT32_MAX;

    for (int i = 0; i < machines.size(); i++) {
        current += machines[i];

        if (current == margin * (i + 1)) {
            vector <int> hold(machines.begin() + prev, machines.begin() + i + 1);
            ans = min(ans, helper(hold));
            current = 0;
            prev = i + 1;
        }
    }

    vector <int> hold(machines.begin() + prev, machines.end());
    ans = min(ans, helper(hold));

    return ans;
}

int main() {
    return 0;
}