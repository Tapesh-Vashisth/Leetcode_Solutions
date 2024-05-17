#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

long long power2(int x) {
    long long ret = 1;
    for (int i = 0; i < x; i++) {
        ret = 2 * ret;
        ret = ret % mod;
    }

    return ret;
}

vector <vector <int>> dp;

int helper(int index, int currentMask, vector <int> & reduced, vector <int> & freq, vector <int> & primeFact) {
    if (index >= reduced.size()) {
        if (currentMask == 0) {
            return 0;
        }

        return 1;
    }

    if (dp[index][currentMask] != -1) {
        return dp[index][currentMask];
    } 

    long long ret = 0;

    // not take 
    ret += helper(index + 1, currentMask, reduced, freq, primeFact);
    ret %= mod;

    // take 
    if ((primeFact[reduced[index]] & currentMask) == 0) {
        ret += ((reduced[index] == 1 ? (power2(freq[reduced[index]]) - 1) : freq[reduced[index]]) * helper(index + 1, (currentMask | primeFact[reduced[index]]), reduced, freq, primeFact)) % mod;
        ret %= mod;
    }

    return dp[index][currentMask] = ret;
}

int numberOfGoodSubsets(vector<int>& nums) {
    vector <int> freq(31, 0);

    for (auto it: nums) {
        freq[it]++;
    }        

    vector <int> primeFact(31, -1);

    primeFact[1] = 0;

    vector <int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    for (int i = 2; i < 31; i++) {
        int hold = i;

        int mask = 0;
        for (int j = 0; j < primes.size(); j++) {
            int counter = 0;
            while (hold && hold % primes[j] == 0) {
                counter++;
                hold = hold / primes[j];
            }

            if (counter == 1) {
                mask = mask | (1 << j);
            } else if (counter > 1) {
                mask = -1;
                break;
            }
        }

        primeFact[i] = mask;
    }


    vector <int> reduced;

    for (int i = 1; i < 31; i++) {
        if (freq[i] > 0 && primeFact[i] != -1) {
            reduced.push_back(i);
        }
    }

    dp = vector <vector <int>> (reduced.size(), vector <int> (1025, -1));

    return helper(0, 0, reduced, freq, primeFact);
}

int main() {
    return 0;
}