#include <iostream>
#include <vector>
using namespace std;

long long cal(vector <int> & nums, vector <int> & cost, int val) {
    long long total = 0;
    for (int j = 0; j < nums.size(); j++) {
        total += ((long long)cost[j]) * abs(nums[j] - val);
    }

    return total;
}    

long long minCost(vector<int>& nums, vector<int>& cost) {
    long long low = 1;
    long long high = 1e6 + 5;

    long long ans = INT64_MAX;

    while (low < high) {
        long long mid = (low + high)/2;

        long long val = cal(nums, cost, mid);
        long long frontVal = cal(nums, cost, mid + 1);
        long long prevVal = cal(nums, cost, mid - 1);

        ans = min(ans, val);
        if (frontVal > val && val > prevVal) {
            high = mid;
        } else if (frontVal < val && val < prevVal) {
            low = mid + 1;
        } else {
            break;
        }
    }

    return ans;
}

int main() {
    return 0;
}