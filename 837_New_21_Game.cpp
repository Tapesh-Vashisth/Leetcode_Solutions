#include <iostream>
#include <vector>
using namespace std;

double new21Game(int n, int k, int maxPts) {
    vector <double> store(n + 1, 0);
    store[0] = 1;

    double total = 1;
    for (int i = 1; i <= n; i++) {
        double hold = total/maxPts;
        store[i] = hold;
        if (i < k) {
            total += hold;
        }

        if (i >= maxPts) {
            total -= store[i - maxPts];
        }
    }


    double ans = 0;

    for (int i = k; i <= n; i++) {
        ans += store[i] > 0 ? store[i] : 0;
    }

    return ans > 1 ? 1 : ans;
}

int main() {
    return 0;
}
