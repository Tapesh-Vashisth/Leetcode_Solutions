#include <iostream>
#include <vector>
using namespace std;

bool canReach(vector<int>& arr, int start){
    vector <int> dp (arr.size(), 0);

    // moving forward 
    for (int i = 0; i < arr.size(); i++){
        // plus 
        if (i + arr[i] < arr.size() && arr[i + arr[i]] == 0){
            dp[i] = 1;
        }

        // minus
        if (i - arr[i] >= 0 && (arr[i - arr[i]] == 0 || dp[i - arr[i]] == 1)){
            dp[i] = 1;
        }
    }

    // moving backward 
    for (int i = arr.size() - 1; i >= 0; i--){
        // minus 
        if (i - arr[i] >= 0 && (arr[i - arr[i]] == 0 || dp[i - arr[i]] == 1)){
            dp[i] = 1;
        }

        // plus 
        if (i + arr[i] < arr.size() && (arr[i + arr[i]] == 0 || dp[i + arr[i]] == 1)){
            dp[i] = 1;
        }
    }

    return dp[start];
}

int main(){
    return 0;
}