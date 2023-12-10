#include <iostream>
#include <vector>
using namespace std;

int totalMoney(int n) {  
    int hold = 0;
    int current = 0;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 7 == 0) {
            hold++;
            current = hold;
            ans += current;
        } else {
            current++;
            ans += current;
        }
    }        

    return ans;
}

int main() {
    return 0;
}