#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int trapRainWater(vector<vector<int>>& heightMap) {
    int ans = 0;
    int height = heightMap.size();
    int width = heightMap[0].size();
    vector <vector <pair <int, int>>> store(height, vector <pair <int, int>> (width, {-1, -1}));
    for (int i = 1; i < heightMap.size() - 1; i++) {
        for (int j = 1; j < heightMap[i].size() - 1; j++) {
            if (store[i - 1][j].first != -1 && store[i][j - 1].first != -1) {
                
            } else if (store[i - 1][j].first != -1) {
                if (store[i - 1][j].second >= 1) {
                    store[i][j].first = store[i - 1][j].first;
                    store[i][j].second = store[i - 1][j].second - 1;
                }
            } else if (store[i][j - 1].first != -1) {
                if (store[i][j - 1].second >= 1) {
                    store[i][j].first = store[i][j - 1].first;
                    store[i][j].second = store[i][j - 1].second - 1;
                }
            } else {

            }
        }
    }

    return ans;
}

int main() {
    return 0;
}