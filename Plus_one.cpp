#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits){
    int carry = 0;
    for (int i = 0; i < digits.size(); i++){
        int start = digits[i];
        digits[i] = digits[i] + 1 + carry;
        if (start == 9){
            carry = 1;
        }
    }
    if (carry){
        digits.insert(digits.begin(), carry);
    }

    return digits;
}

int main(){
    
    return 0;
}