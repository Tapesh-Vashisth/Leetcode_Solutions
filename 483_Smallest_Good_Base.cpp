#include <iostream>
#include <vector>
using namespace std;

long long check(int len, long long base, long long num) {
    long long store = 0;
    long long keep = 1;
    long long mx = num;
    for (int i = 0; i < len; i++) {
        store += keep; 
        
        if (i == len - 1) {
            return store;
        }

        if (keep >= (mx + base - 1) / base) {
            return num + 1;
        }

        keep = keep * base;
    }

    return store;
}

string smallestGoodBase(string n) {
    long long num = stol(n);
    for (int i = 62; i > 0; i--) {
        long long low = 2;
        long long high = 1e18;

        while (low <= high) {
            long long mid = low + (high - low)/2;

            long long keep = check(i, mid, num);

            if (keep > num) {
                high = mid - 1;
            } else if (keep < num) {
                low = mid + 1;
            } else {
                return to_string(mid);
            }
        }
    }        

    return "";
}

int main() {
    return 0;
}