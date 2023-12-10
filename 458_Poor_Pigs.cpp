#include <iostream>
#include <vector>
using namespace std;

bool check(int buckets, int pigs, int minutestoDie, int minutesToTest) {
    int hold = buckets;
    int time = 0;

    while (time <= minutesToTest) {
        time += minutestoDie;

        if (time <= minutesToTest) {
            hold -= pigs;
            hold = hold/(pigs + 1);
            pigs--;
        }
    }

    if (hold <= 1) {
        return true;
    }

    return false;
}

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int low = 1;
    int high = buckets;

    int ans = buckets;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (check(buckets, mid, minutesToDie, minutesToTest)) {
            ans = min(ans, mid);
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
