#include <iostream>
#include <vector>
using namespace std;



bool issquare(int n){
    int low = 0;
    int high = n;
    while (low <= high){
        int mid = (low + high)/2;
        if (mid * mid == n){
            return true;
        }else if (mid * mid > n){
            high = mid - 1;
        }else{
            low = mid + 1;
        } 
    }

    return false;
}


int get_start(vector <int>& squares, int n){
    int low = 0;
    int high = squares.size() - 1;
    while (low < high){
        int mid = (low + high)/2;
        if (squares[mid] == n){
            return mid;
        }else if(squares[mid] > n){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return low;
}


int numSquares(int n) {
    // creating the square buffer 
    vector <int> squares = {0};
    for (int i = 1; i <= 100; i++){
        squares.push_back(i * i);
    }

    vector <int> dp = {0};
    // applying dp
    for (int i = 1; i <= n; i++){
        // cout << "hi" << endl;
        int mx = i;
        int q;
        int m;
        int start = get_start(squares, i);
        for (int j = start; j >= 1; j--){
            if (i/squares[j] != 0){
                q = i / squares[j];
                m = dp[i % squares[j]];
                if (q + m < mx){
                    mx = q + m;
                }
            }
        }
        dp.push_back(mx);
        // cout << dp[i] << " ";
    }
    // cout << dp[n] << endl;
    return dp[n];
}

int main(){
    int x = numSquares(26);
    cout << "hi" << endl;
    return 0;
}