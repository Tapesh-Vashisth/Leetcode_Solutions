#include <iostream>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        long long low = 0;
        long long high = n;

        if (n == 0) {
            return 0;
        }
        
        long long ans = 1;
        while (low < high) {
            long long mid = (low + high)/2;
            if (mid * mid > n) {
                high = mid;
            } else if (mid * mid < n) {
                low = mid + 1;
                ans = max(mid, ans);
            } else {
                return mid;
            }
        }

        return ans;
    }
};