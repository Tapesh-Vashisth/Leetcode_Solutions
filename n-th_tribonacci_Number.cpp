#include <iostream>
using namespace std;

int tribonacci(int n){
    int storage[38];
    storage[0] = 0;
    storage[1] = 1;
    storage[2] = 1;
    for (int i = 2; i < 38; i++){
        storage[i] = storage[i] + storage[i - 1] + storage[i - 2];
    }

    return storage[n];
}

int main(){
     
}