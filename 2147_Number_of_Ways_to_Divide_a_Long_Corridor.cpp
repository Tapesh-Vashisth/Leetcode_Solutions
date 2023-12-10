#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

int numberOfWays(string corridor) {

    int n = corridor.size();
    vector <int> seats;
    for (int i = 0; i < n; i++) {
        if (corridor[i] == 'S') {
            seats.push_back(i);
        }
    }

    if (seats.size() % 2 != 0 || seats.size() == 0) {
        return 0;
    }

    long long ans = 1;
    for (int i = 1; i < seats.size(); i++) {
        if (i % 2 == 0) {
            ans = ((ans % mod) * (seats[i] - seats[i - 1])) % mod;
        }
    }

    return ans;
}

int main() {
    return 0;
}