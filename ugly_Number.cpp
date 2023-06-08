#include <iostream>
#include <vector>
using namespace std;

vector <int> sieve(int n){
    vector <int> store(n + 1, 1);
    vector <int> primes;
    store[1] = -1;
    store[0] = -1;
    for (int i = 1; i*i <= n; i++){
        if (store[i] != -1){
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i){
                store[j] = -1;
            }
        }
    }

    for (int i = 0; i < primes.size(); i++){
        cout << primes[i] << endl;
    }

    return primes;
}

bool isUgly(int n) {
    vector <int> primes = sieve(n);
    for (int i = 0; i < primes.size(); i++){
        if ((primes[i] != 2 && primes[i] != 3 && primes[i] != 5) && (n % primes[i] == 0)){
            return false;
        }
    }
    return true;
}

int main(){
    cout << isUgly(50) << endl;
    return 0;
}