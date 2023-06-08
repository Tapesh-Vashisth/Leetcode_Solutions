#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int prev = arr[1] - arr[0];

    for (int i = 2; i < arr.size(); i++) {
        if (arr[i] - arr[i - 1] != prev) {
            return false;
        }
    }

    return true;
}

int main() {
    return 0;
}