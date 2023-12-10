#include <iostream>
#include <vector>
using namespace std;

bool canReach(vector<int>& arr, int start) {
    vector <bool> dp(arr.size(), false);

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            dp[i] = true;
        }
    }        

    while (true) {
        bool decider = false;
        for (int i = 0; i < arr.size(); i++) {
            if (i + arr[i] < arr.size()) {
                if (dp[i + arr[i]] == true && dp[i] == false) {
                    decider = true;
                    dp[i] = dp[i + arr[i]];
                }
            } 

            if (i - arr[i] >= 0) {
                if (dp[i - arr[i]] == true && dp[i] == false) {
                    decider = true;
                    dp[i] = dp[i - arr[i]];
                }
            }
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (i + arr[i] < arr.size()) {
                if (dp[i + arr[i]] == true && dp[i] == false) {
                    decider = true;
                    dp[i] = dp[i + arr[i]];
                }
            } 

            if (i - arr[i] >= 0) {
                if (dp[i - arr[i]] == true && dp[i] == false) {
                    decider = true;
                    dp[i] = dp[i - arr[i]];
                }
            }
        }

        if (!decider) {
            break;
        }
    }

    return dp[start];
}

int main(){
    return 0;
}