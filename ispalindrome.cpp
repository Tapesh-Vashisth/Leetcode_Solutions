#include <iostream>
#include <math.h>
using namespace std;

int No_of_digits(int x){
    int count = 0;
    while (x){
        x = x/10;
        count++;
    }
    return count;
}

bool isPalindrome(int x) {
    int times = No_of_digits(x);
    int forback = pow(10, (times - 1));
    int num = 0;
    for (int i = 0; i < times/2; i++){
        num = num*10 + (x%10);
        x = x/10;
    }

    if (times % 2 == 0){
        if (num == x){
            return 1;
        }else{
            return 0;
        }
    }else{
        x = x/10;
        if (num == x){
            return 1;
        }else{
            return 0;
        }
    }

    return true;
}


int main(){
    int x = 100040011;
    // cout << No_of_digits(x) << endl;
    cout << isPalindrome(x) << endl;
    return 0;   
}