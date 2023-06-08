#include <iostream>
using namespace std;

int helper(int n, int prev, int counter){
    if (counter > n){
        return 1;
    }else{
        int total = 0;
        for (int i = 1; i <= n; i++){
            if (i < prev){
                
            }else if(i > prev){
                
            } 
        }

        return total;
    }
}

int numTrees(int n){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans += helper(n, i, 1);
    }

    return ans;
}

int main(){

    return 0;
}