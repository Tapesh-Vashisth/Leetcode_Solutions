#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

long long putMarbles(vector<int>& weights, int k) {
    priority_queue <int, vector<int>, greater<int>> storeMin;
    priority_queue <int> storeMax;

    for (int i = 1; i < weights.size(); i++) {
        storeMin.push(weights[i] + weights[i - 1]);
        storeMax.push(weights[i] + weights[i - 1]);
    }

    long long mn = weights[0] + weights[weights.size() - 1];
    long long mx = weights[0] + weights[weights.size() - 1];

    for (int i = 0; i < k - 1; i++) {
        mn += storeMin.top();
        mx += storeMax.top();
        storeMin.pop();
        storeMax.pop();
    }


    return mx - mn;
}

int main() {
    return 0;
}