#include <iostream>
#include <vector>
using namespace std;

bool check(vector <int> & compose, int alloys, vector <int> & costs, vector <int> & stocks, int budget) {
    for (int i = 0; i < compose.size(); i++) {      
        int remain = compose[i] - stocks[i];
        if (remain > 0) {
            budget -= costs[i] * remain;
        }

        if (budget < 0) {
            return false;
        }
    }

    return true;
}

int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
    int ans = 0;
    for (int i = 0; i < composition.size(); i++) {
        int low = 0;
        int high = 1e8;
        int mx = 0;
        while (low < high) {
            int mid = low + (high - low)/2;

            if (check(composition[i], mid, cost, stock, budget)) {
                mx = max(mx, mid);
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        ans = max(ans, mx);
    }

    return ans;
}

int main() {

    return 0;
}