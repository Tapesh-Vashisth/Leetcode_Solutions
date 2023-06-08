#include <iostream>
using namespace std;

int memory[50]; 
int cou = 0;

int climbStairs(int n){
    if (n == 0 || n == 1){
        return 1;
    }else if (n < 0){
        return 0;
    }else{
        cou++;
        int first;
        int second;
        if (memory[n - 1] != -2){
            first = memory[n - 1];
        }else{
            first = climbStairs(n - 1);
            memory[n - 1] = first;
        }

        if (memory[n - 2] != -2){
            second = memory[n - 2];
        }else{
            second = climbStairs(n - 2);
            memory[n - 2] = second;
        }
        return first + second;
    }
}

int main(){
    for (int i = 0; i < 50; i++){
        memory[i] = -2;
    }
    memory[0] = 1;
    memory[1] = 1;
    cout << climbStairs(45) << endl;
    cout << cou << endl;
    return 0;
}