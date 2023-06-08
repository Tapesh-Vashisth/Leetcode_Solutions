#include <iostream>
#include <vector>
using namespace std;

int hammingDistance(int x, int y){
    int count = 0;
    while (x != 0 && y != 0){
        int bit1 = x&1;
        int bit2 = y&1;
        if (bit1 ^ bit2 == 1){
            count++;
        }
        x = x >> 1;
        y = y >> 1; 
    }

    while (x){
        int bit = x&1;
        if (bit == 1){
            count++;
        }
        x = x >> 1;
    }

    while (y){
        int bit = y&1;
        if (bit == 1){
            count++;
        }
        y = y >> 1;
    }

    return count;
}

int main(){
    cout << hammingDistance(4, 1) << endl;
    return 0;
}