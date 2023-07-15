#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool comparator (vector <int> first, vector <int> second) {
        if (first[1] < second[1]) {
            return true;
        } else {
            return false;
        }
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        map <int, pair <int, vector <int>>> store;

        for (int i = 0; i < events.size(); i++) {
            int start = events[i][0];
            int end = events[i][1];
            int reward = events[i][2];


            auto pos = store.lower_bound(-(start - 1));
            auto prev = store.lower_bound(-end);

            if (pos == store.end()) {
                if (prev == store.end()) {
                    store[-end] = {reward, {reward}};
                } else {
                    if (reward > (*prev).second.first) {
                        store[-end] = {reward, {reward}};
                    } else {
                        store[-end] = (*prev).second;
                    }
                }
            } else {
                if ((*pos).second.second.size() < k) {
                    if ((*pos).second.first + reward > (*prev).second.first) {
                        store[-end] = (*pos).second;
                        store[-end].first += reward;
                        store[-end].second.push_back(reward);
                    } else {
                        store[-end] = (*prev).second;
                    }
                } else {
                    int mn = INT32_MAX;
                    int mnpos = -1;
                    for (int i = 0; i < (*pos).second.second.size(); i++) {
                        if ((*pos).second.second[i] < mn) {
                            mn = (*pos).second.second[i];
                            mnpos = i;
                        }
                    }

                    if ((*pos).second.first - mn + reward > (*prev).second.first) {
                        store[-end] = (*pos).second;
                        store[-end].first = (*pos).second.first - mn + reward;
                        store[-end].second[mnpos] = reward;
                    } else {
                        store[-end] = (*prev).second;
                    }
                }
            }
        }

        int first = store[-events[events.size() - 1][1]].first;

        sort(events.begin(), events.end(), comparator);

        map <int, pair <int, vector <int>>> store2;

        for (int i = 0; i < events.size(); i++) {
            int start = events[i][0];
            int end = events[i][1];
            int reward = events[i][2];


            auto pos = store2.lower_bound(-(start - 1));
            auto prev = store2.lower_bound(-end);

            if (pos == store2.end()) {
                if (prev == store2.end()) {
                    store2[-end] = {reward, {reward}};
                } else {
                    if (reward > (*prev).second.first) {
                        store2[-end] = {reward, {reward}};
                    } else {
                        store2[-end] = (*prev).second;
                    }
                }
            } else {
                if ((*pos).second.second.size() < k) {
                    if ((*pos).second.first + reward > (*prev).second.first) {
                        store2[-end] = (*pos).second;
                        store2[-end].first += reward;
                        store2[-end].second.push_back(reward);
                    } else {
                        store2[-end] = (*prev).second;
                    }
                } else {
                    int mn = INT32_MAX;
                    int mnpos = -1;
                    for (int i = 0; i < (*pos).second.second.size(); i++) {
                        if ((*pos).second.second[i] < mn) {
                            mn = (*pos).second.second[i];
                            mnpos = i;
                        }
                    }

                    if ((*pos).second.first - mn + reward > (*prev).second.first) {
                        store2[-end] = (*pos).second;
                        store2[-end].first = (*pos).second.first - mn + reward;
                        store2[-end].second[mnpos] = reward;
                    } else {
                        store2[-end] = (*prev).second;
                    }
                }
            }
        }

        return max(first, store2[-events[events.size() - 1][1]].first);
    }
};

int main() {

    return 0;
}