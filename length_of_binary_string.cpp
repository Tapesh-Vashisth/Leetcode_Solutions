#include <iostream>
using namespace std;


int helper(int val, int n){
    if (n == 0){
        return 1;
    }else{
        int zeros = helper(0, n - 1);
        int ones = helper(1, n - 1);

        if (val == 1){
            return zeros;
        }else{
            return zeros + ones;
        }
    }
}

int length_consecutive(int n){
    int first = helper(0, n - 1);
    int second = helper(1, n - 1);

    return first + second;
}



int main(){
    int n;
    cin >> n;
    cout << length_consecutive(n) << endl;
    return 0;
}