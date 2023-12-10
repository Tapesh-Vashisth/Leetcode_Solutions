#include <iostream>
#include <vector>
using namespace std;

int minTaps(int n, vector<int>& ranges) {
    vector <int> store(n + 1, -1);
    for (int i = 0; i < ranges.size(); i++) {
        int start = i - ranges[i];
        int end = i + ranges[i];

        if (start > 0) {
            store[start] = max(store[start], end);
        } else {
            store[0] = max(store[0], end);
        }
    }           

    for (auto it: store) {
        cout << it << " ";
    }   
    cout << endl;

    int endpoint = store[0];
    int current = 1;
    int ans;
    while (true) {
        int temp = current;
        if (temp <= endpoint + 1) {

        } else {

        }
    }

    return 0;
}

int main() {
    return 0;
}