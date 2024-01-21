#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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

    vector <vector <pair <int, vector <int>>>> dp(6, vector <pair <int, vector <int>>> (l + 1, {-1, {0, 0, 0, 0, 0}}));

    dp[0][0] = {0, {0, 0, 0, 0, 0}};

    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j <= l; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j - heights[i - 1] >= 0 && dp[i - 1][j - heights[i - 1]].first != -1) {
                if (dp[i - 1][j - heights[i - 1]].first + 1 > dp[i][j].first) {
                    dp[i][j].first = dp[i - 1][j - heights[i - 1]].first + 1;
                    dp[i][j].second = dp[i - 1][j - heights[i - 1]].second;
                    dp[i][j].second[i - 1]++;
                }
            }

            if (j - heights[i - 1] >= 0 && dp[i][j - heights[i - 1]].first != -1) {
                if (dp[i][j - heights[i - 1]].first + 1 > dp[i][j].first) {
                    dp[i][j].first = dp[i][j - heights[i - 1]].first + 1;
                    dp[i][j].second = dp[i][j - heights[i - 1]].second;
                    dp[i][j].second[i - 1]++;
                }
            }
        }
    }

    if (dp[5][l].first == -1) {
        cout << "Impossible" << endl;
    } else {
        set <pair <int, int>, comp> store;

        for (int i = 0; i < dp[5][l].second.size(); i++) {
            if (dp[5][l].second[i] > 0) {
                store.insert({dp[5][l].second[i], heights[i]});
            }
        }

        for (auto it: store) {
            cout << it.second << " ";
        }
        cout << endl;
    }

    return 0;
}