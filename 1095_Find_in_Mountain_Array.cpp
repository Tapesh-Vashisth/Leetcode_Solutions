#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector <int> arr;

    int bisearch(int low, int high, int target, MountainArray &mountainArr, int type) {
        if (type == 0) {
            while (low <= high) {
                int mid = low + (high - low)/2;

                int arrMid = mountainArr.get(mid);

                if (target < arrMid) {
                    high = mid - 1;
                } else if (target > arrMid) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            }
        } else {
            while (low <= high) {
                int mid = low + (high - low)/2;

                int arrMid = mountainArr.get(mid);

                if (target < arrMid) {
                    low = mid + 1;
                } else if (target > arrMid) {
                    high = mid - 1;
                } else {
                    return mid;
                }
            }
        }

        return -1;
    }

    int findPeak(int low, int high, MountainArray &mountainArr) {
        while (low < high) {
            int mid = low + (high - low)/2;
            int arrMid1 = mountainArr.get(mid);
            int arrMid2 = mountainArr.get(mid + 1);
            
            if (arrMid1 < arrMid2) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        arr = vector <int> (n, -1);

        int peak = findPeak(0, n - 1, mountainArr);
        int first = bisearch(0, peak, target, mountainArr, 0);

        if (first != -1) {
            return first;
        }

        int second = bisearch(peak + 1, n - 1, target, mountainArr, 1);
        return second;
    }
};

int main() {
    return 0;
}