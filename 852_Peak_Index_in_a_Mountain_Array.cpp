#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = 0;
    while (low < high) {
        int mid1 = low + (high - low)/3;
        int mid2 = low + (2*(high - low))/3;

        if (arr[mid1] > arr[ans]) {
            ans = mid1;
        }

        if (arr[mid2] > arr[ans]) {
            ans = mid2;
        }

        if (arr[low] > arr[ans]) {
            ans = low;
        }

        if (arr[high] > arr[ans]) {
            ans = high;
        }

        if (arr[mid1] == arr[mid2]) {
            low = mid1 + 1;
            high = mid2;
        } else if (arr[mid1] > arr[mid2]) {
            high = mid2 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return ans;
}

int main() {
    return 0;
}