#include <iostream>
using namespace std;

int smallestEvenMultiple(int n) {
    if (n%2 == 0){
        return n;
    }else{
        return n * 2;
    }        
}

int main(){
    return 0;
}