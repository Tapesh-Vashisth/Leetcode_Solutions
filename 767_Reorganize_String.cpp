#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;


string reorganizeString(string s) {
    priority_queue <pair <int, int>> store;
    vector <int> counter(26, 0);
    for (auto it: s) {
        counter[it - 'a']++;
    }        

    for (int i = 0; i < counter.size(); i++) {
        if (counter[i] > 0) {
            store.push({counter[i], i});
        }
    }

    if (store.top().first > (s.size() + 1)/2) {
        return "";
    }    

    string ans = "";

    list <int> linked;
    pair <int, int> hold = store.top();
    store.pop();

    while (hold.first > 0) {
        linked.push_back(hold.second);
        hold.first--;
    }

    auto it = linked.begin();
    while (!store.empty()) {
        hold = store.top();
        store.pop();

        while (hold.first) {
            if (it == (--linked.end())) {
                if ((*it) == hold.second) {
                    it = linked.begin();
                } else {
                    linked.push_back(hold.second);
                    hold.first--;
                }
            } else {
                auto forward = it;
                forward++;
                if ((*it) == hold.second || (*forward) == hold.second) {
                    it++;
                } else {
                    it++;
                    linked.insert(it, 1, hold.second);
                    hold.first--;
                }
            }
        }
    }

    for (auto it: linked) {
        ans.push_back('a' + (it));
    }

    return ans;
}

int main() {
    return 0;
}