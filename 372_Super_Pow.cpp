#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1337;

void divide(vector <int> & b, int x) {
    int carry = 0;

    for (int i = 0; i < b.size(); i++) {
        int num = carry * 10 + b[i];
        b[i] = num / 2;
        carry = num % 2;
    }
}

bool check(vector <int> & b) {
    for (auto it: b) {
        if (it != 0) {
            return true;
        }
    }

    return false;
}


int superPow(int a, vector<int>& b) {
    int multiplier = a;

    int ans = 1;
    while (check(b)) {
        if (b[b.size() - 1] % 2 == 1) {
            ans = ((ans % mod) * (multiplier % mod)) % mod;
        }

        divide(b, 2);
        
        multiplier = ((multiplier % mod) * (multiplier % mod)) % mod;    
    }

    return ans;
}

int main() {
    return 0;
}