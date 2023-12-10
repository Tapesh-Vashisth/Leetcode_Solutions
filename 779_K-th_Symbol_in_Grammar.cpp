#include <iostream>
#include <vector>
using namespace std;

int helper(int n, int k) {
    if (k == 0) {
        return 0;
    } 

    int hold = helper(n - 1, k/2);

    if (hold == 0) {
        if (k % 2) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (k % 2) {
            return 0;
        } else {
            return 1;
        }
    }
}

int kthGrammar(int n, int k) {
    n--, k--;        

    return helper(n, k);
}

int main() {
    return 0;
}