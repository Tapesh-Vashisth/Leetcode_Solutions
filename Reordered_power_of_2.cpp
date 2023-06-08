#include <iostream>
#include <vector>
using namespace std;

int getithbit(int x, int i){
    int bit = 1 << (i - 1);
    return (x & bit ? 1 : 0);
}

int setithbit(int x, int i){
    return (x | (1 << (i - 1)));
}

int powerof2(long long x){
    if ((x & (x - 1)) == 0){
        return 1;
    }else{
        return 0;
    }
}

int number_of_digits(long long n){
    int count = 0;
    while (n){
        n = n/10;
        count++;
    }

    return count;
}

bool check(vector <int> &digits, int bitmask, long long number){
    vector <bool> ans;
    for (int i = 0; i < digits.size(); i++){
        for (int i = 0; i  < ans.size(); i++){
            if (ans[i] == 1){
                return true;
            }
        }
        int decider = 0;
        for (int i = 0; i < digits.size(); i++){
            if (getithbit(bitmask, i + 1) == 0){
                decider = 1;
                break;
            }
        }

        if (decider){
            if (getithbit(bitmask, i + 1) == 0){
                ans.push_back(check(digits, setithbit(bitmask, i + 1), number * 10 + digits[i]));
            }
        }else{
            if (number_of_digits(number) != digits.size()){
                return false;
            }else{
                if (powerof2(number)){
                    return 1;
                }else{
                    return 0;
                }
            }
        } 
    }

    for (int i = 0; i  < ans.size(); i++){
        if (ans[i] == 1){
            return true;
        }
    }

    return false;
}


bool reorderedPowerOf2(int n) {
    vector <int> digits;        
    int m = n;

    while (m){
        int temp = m%10;
        digits.push_back(temp);
        m = m/10;
    }

    return check(digits, 0, 0);    
}

int main(){
    cout << reorderedPowerOf2(1023) << endl;
    return 0;
}