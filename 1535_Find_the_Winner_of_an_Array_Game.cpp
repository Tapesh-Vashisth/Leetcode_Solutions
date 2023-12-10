#include <iostream>
#include <vector>
using namespace std;

int getWinner(vector<int>& arr, int k) {
    int mx = arr[0];
    int current = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= mx) {
            current++;
        } else {
            current = 1;
            mx = arr[i];
        }

        if (current == k) {
            return mx;
        }
    }

    return mx;
}

int main() {
    return 0;
}