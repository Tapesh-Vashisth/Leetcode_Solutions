#include <iostream>
using namespace std;

double pow(int x, int n){
    if (n == 0){
        return 1;
    }else if(n == 1){
        return x;
    }else{
        if (n % 2 == 0){
            int p = pow(x, n/2);
            return p * p;
        }else{
            int p = pow(x, n/2);
            return x * p * p;
        }
    }
}

int main(){
    cout << pow(4, 5) << endl;
    return 0;
}