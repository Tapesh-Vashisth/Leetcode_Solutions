#include <iostream>
#include <vector>
using namespace std;

const int mod  = 1337;

// to future me: use the string notation itself for this question 

int helper(int a, long long b){
    if (b == 0){
        return 1;
    }

    if (b == 1){
        return a % mod;
    }

    int cal = helper(a, b/2);
    if (b % 2 == 0){
        return (cal*cal)%mod;
    }else{
        return (2*(cal*cal)%mod)%mod;
    }
}

long long extract(vector <int>& b){
    long long ans = 0;
    long long mul = 1;
    for (int i = b.size() - 1; i >= 0; i--){
        ans += mul*b[i];
        mul *= 10;
    }
    return ans;
}

int superPow(int a, vector<int>& b) {
    long long p = extract(b);
    return helper(a, p);
}

int main(){
    return 0;
}