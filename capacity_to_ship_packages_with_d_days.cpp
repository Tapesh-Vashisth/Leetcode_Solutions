#include <iostream>
#include <vector>
using namespace std;


bool check(vector <int> &weights, int mid, int days, vector <int> &prefix) {
    int prev = 0;
    for (int i = 0; i < days; i++) {
        int pos = lower_bound(prefix.begin(), prefix.end(), prev + mid) - prefix.begin();

        if (pos == prefix.size()) {
            return true;
        }

        if (prefix[pos] != prev + mid) {
            pos--;
        }
    

        prev = prefix[pos];
    }

    return false;
}


int shipWithinDays(vector<int>& weights, int days) {
    vector <int> prefix = {weights[0]};
    int n = weights.size();
    for (int i = 1; i < weights.size(); i++) {
        prefix.push_back(prefix[n - 1] + weights[i]);
    }

    int low = 0;        
    int high = prefix[n - 1];
    int ans;
    while (low < high) {
        int mid = (low + high)/2;
        if (check(weights, mid, days, prefix)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    return 0;
}