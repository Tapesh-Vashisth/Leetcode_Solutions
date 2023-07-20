#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack <int> store;
    vector <int> ans;

    for (auto it: asteroids) {
        if (it < 0) {
            while (!store.empty() && store.top() < -it) {
                store.pop();
            }

            if (!store.empty() && store.top() == -it) {
                store.pop();
            } else {
                if (store.empty()) {
                    ans.push_back(it);
                }
            }
        } else {
            store.push(it);
        }
    }

    stack <int> store2;

    while (!store.empty()) {
        store2.push(store.top());
        store.pop();
    }

    while (!store2.empty()) {
        ans.push_back(store2.top());
        store2.pop();
    }

    return ans;
}

int main() {
    return 0;
}