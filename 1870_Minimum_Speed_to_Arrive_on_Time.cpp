#include <iostream>
#include <vector>
using namespace std;

int minSpeedOnTime(vector<int>& dist, double hour) {
    int low = 1;
    int high = 1e9;

    int ans = INT32_MAX;
    while (low <= high) {
        int mid = low + (high - low)/2;

        double totalTimeNeeded = 0;
        for (int i = 0; i < dist.size(); i++) {
            if (i == dist.size() - 1) {
                totalTimeNeeded += dist[i]/(double)mid; 
            } else {
                int time = (dist[i] + mid - 1)/mid;
                totalTimeNeeded += time;
            }
        }


        if (totalTimeNeeded <= hour) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }


    return ans == INT32_MAX ? -1 : ans;
}

int main() {
    return 0;
}