#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int start = 1;

    for (int i = 1; i < arr.size(); i++) {
        start++;
        start = min(start, arr[i]);
    }

    return start;
}

int main() {
    return 0;
}