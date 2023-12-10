#include <iostream>
#include <vector>
using namespace std;

long long fact(long long x) {
    long long ret = 1;
    for (int i = 1; i <= x; i++) {
        ret *= i;
    }

    return ret;
}

void helper(string & cons, vector <bool> & store, int k) {
    if (cons.size() == store.size() - 1) {
        return ;
    }

    long long gap = fact(store.size() - cons.size() - 2);

    long long start = 0;

    for (int i = 1; i < store.size(); i++) {
        if (store[i] == false) {
            long long end = start + gap;
            if (k >= start + 1 && k <= end) {
                cons.push_back('0' + i);
                store[i] = true;
                helper(cons, store, k - start);
                break;
            } else {
                start = end;
            }
        }
    }
}

string getPermutation(int n, int k) {
    vector <bool> store(n + 1, false);
    string ans = "";
    helper(ans, store, k);

    return ans;
}

int main() {
    return 0;
}