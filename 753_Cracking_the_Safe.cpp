#include <iostream>
#include <vector>
using namespace std;

vector <bool> hashed;
string ans;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool helper(string & cons, int n, int k, int possible, int taken) {
    if (cons.size() == possible && taken == (possible - (n - 1))) {
        ans = cons;
        return true;
    }

    if (cons.size() >= n - 1) {
        for (int i = 0; i < k; i++) {
            cons.push_back('0' + i);

            int hold = stoi(cons.substr(cons.size() - n, n));
            if (!hashed[hold]) {
                hashed[hold] = true;
                bool check = helper(cons, n, k, possible, taken + 1);
                if (check) {
                    return true;
                }    
                hashed[hold] = false;
            }

            cons.pop_back();
        }
    } else {
        for (int i = 0; i < k; i++) {
            cons.push_back('0' + i);
            bool check = helper(cons, n, k, possible, taken);
            if (check) {
                return true;
            }
            cons.pop_back();
        }
    }

    return false;
}

string crackSafe(int n, int k) {
    hashed.resize(10000, false);
    string cons = "";     
    ans = "";
    int possible = binpow(k, n);
    helper(cons, n, k, possible + (n - 1), 0);       
    return ans;
}

int main() {
    cout << crackSafe(2, 2) << endl;
    return 0;
}