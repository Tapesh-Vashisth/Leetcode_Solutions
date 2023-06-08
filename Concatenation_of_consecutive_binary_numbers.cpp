#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int concatenatedBinary(int n){
    long long mod = 1e9 + 7;
    long long ans = 1;
    for (int i = 2; i <= n; i++){
        int shift = log2(i) + 1;
        for (int j = 0; j < shift; j++){
            ans = (ans * 2) % mod;
        }
        ans = ans + i;
        ans = ans % mod;
    }

    int convert = ans;
    return convert;
}

int main(){
    cout << concatenatedBinary(12) << endl;
    return 0;
}