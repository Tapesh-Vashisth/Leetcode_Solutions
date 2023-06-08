#include <iostream>
#include <cmath>
using namespace std;

int num_of_digits(int x){
    int count = 0;
    while (x){
        count++;
        x = x/10;
    }

    return count;
}

int pow(int x, int n){
    int ans = 1;
    for (int i = 0; i < n; i++){
        ans = ans * x;
    }
    return ans;
}

int reverse(int x){
    int compare1[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7}; 
    int compare2[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7}; 
    int sign = (x < 0 ? -1: 1);
    int count = num_of_digits(x);
    int ans = 0;
    int multiplier = pow(10, count - 1);
    if (sign == 1){
        if (count >= 10){
            int decider = 1;
            int index = 0;
            int flag = 1;
            while (count){
                int digit = (abs(x)/decider)%10;
                if (digit > compare1[index] && flag == 1){
                    return 0;
                }else if(digit < compare1[index] && flag == 1){
                    flag = 0;
                }else if(flag == 1){
                    flag = 1;
                }
                ans += digit * multiplier;
                index++;
                multiplier = multiplier/10;
                decider = decider * 10;
                count--;
            }

            return ans;
        }else{  
            int decider = 1;
            int index = 0;
            while (count){
                int digit = (abs(x)/decider)%10;
                ans += digit * multiplier;
                index++;
                multiplier = multiplier/10;
                decider = decider * 10;
                count--;
            }

            return sign * ans;
        }
    }else{
        if (count >= 10){
            int decider = 1;
            int index = 0;
            int flag = 1;
            while (count){
                int digit;
                if (x == -2147483648){
                    digit = -(x/decider)%10;
                }else{
                    digit = (abs(x)/decider)%10;
                }
                digit = abs(digit);
                if (digit > compare2[index] && flag == 1){
                    return 0;
                }else if(digit < compare2[index] && flag == 1){
                    flag = 0;
                }else if(flag == 1){
                    flag = 1;
                }
                ans += digit * multiplier;
                index++;
                multiplier = multiplier/10;
                decider = decider * 10;
                count--;
            }

            return -ans;
        }else{
            int decider = 1;
            int index = 0;
            while (count){
                int digit = (abs(x)/decider)%10;
                ans += digit * multiplier;
                multiplier = multiplier/10;
                decider = decider * 10;
                index++;
                count--;
            }
            return -ans;
        }
    }
}

int main(){
    cout << reverse(-2147483648) << endl;
    return 0;
}