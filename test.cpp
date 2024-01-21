#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class comp {
    public:
        bool operator()(pair <int, int> a, pair <int, int> b) const {
            if (a.first > b.first) {
                return true;
            } else if (a.first < b.first) {
                return false;
            } else {
                return a.second < b.second;
            }
        }
};

int main() {
    int l;
    cin >> l;

    vector <int> heights;
    for (int i = 0; i < 5; i++) {
        int h;
        cin >> h;
        heights.push_back(h);
    }

    // vector <vector <int>> dp(6, vector <int>> (l + 1, -1}));

    vector <int> dp(l + 1, -1), prev(l + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= l; i++) {
        for (int j = 0; j < 5; j++) {
            if (heights[j] > i || dp[i - heights[j]] == -1) continue;

            if (dp[i] < dp[i - heights[j]] + 1) {
                dp[i] = dp[i - heights[j]] + 1;
                prev[i] = heights[j];
            }
        }
    }



    if (dp[l] == -1) {
        cout << "Impossible" << endl;
    } else {
        set <pair <int, int>, comp> store;

        int temp = l;

        map <int, int> keep;

        while (temp != 0) {
            keep[prev[temp]]++;
            temp = temp - prev[temp];
        }

        for (auto it: keep) {
            store.insert({it.second, it.first});
        }

        for (auto it: store) {
            cout << it.second << " ";
        }
        cout << endl;
    }

    return 0;
}