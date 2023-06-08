#include <iostream>
using namespace std;

int storage[31];

int fib(int n){
    if (n == 0){
        return 0;
    }else if (n == 1){
        return 1;
    }else{
        if (storage[n] != -1){
            return storage[n];
        }

        storage[n] = fib(n - 1) + fib(n - 2);
        return storage[n];
    }
}

int main(){
    for (int i = 0; i < 31; i++){
        storage[i] = -1;
    }
    cout << fib(5) << endl;
    return 0;
}