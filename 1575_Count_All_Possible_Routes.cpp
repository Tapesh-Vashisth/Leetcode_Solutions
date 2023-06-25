#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;
vector <vector <int>> dp;
int helper(vector <int> & locations, int index, int finish, int fuel) {
    if (fuel < 0) {
        return 0;
    } 

    if (dp[index][fuel] != -1) {
        return dp[index][fuel];
    }

    int hold = 0;

    if (index == finish) {
        hold++;
    }

    int i = 0;
    for (auto it: locations) {
        if (i != index) {
            hold = ((hold % mod) + (helper(locations, i, finish, fuel - abs(locations[index] - it)) % mod) % mod);
        }
        i++;
    }


    dp[index][fuel] = hold;

    return hold;
}

int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    dp = vector <vector <int>> (locations.size(), vector <int> (fuel + 1, -1));
    long long ans = helper(locations, start, finish, fuel);

    return ans % mod;
}

int main() {
    return 0;
}