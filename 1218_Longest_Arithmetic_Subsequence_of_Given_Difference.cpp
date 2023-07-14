#include <iostream>
#include <vector>
using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    vector <int> store(500005, 0);

    int mx = 0;
    for (int i = 0; i < arr.size(); i++) {
        int hold = arr[i] - difference;

        store[arr[i] + 20000] = max(store[arr[i] + 20000], store[hold + 20000] + 1);
        mx = max(mx, store[arr[i] + 20000]);
    }       

    return mx;
}

int main() {
    return 0;
}