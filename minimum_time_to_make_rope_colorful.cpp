#include <iostream>
#include <vector>
using namespace std;

int minCost(string colors, vector<int>& neededTime){
    vector <int> mins(26, 0);

    vector <int> dp = {0};

    char prev = colors[0];
    for (int i = 0; i < colors.size(); i++){
        if (prev != colors[i]){
            for (int i = 0; i < mins.size(); i++){
                mins[i] = 0;
            }
        }

        if (mins[colors[i] - 'a'] == 0){
            dp.push_back(dp[dp.size() - 1]);
            mins[colors[i] - 'a'] = neededTime[i];
        }else if(neededTime[i] > mins[colors[i] - 'a']){
            dp.push_back(dp[dp.size() - 1] + mins[colors[i] - 'a']);
            mins[colors[i] - 1] = neededTime[i];
        }else{
            dp.push_back(dp[dp.size() - 1] + neededTime[i]);
        }

        prev = colors[i];
    }

    return dp[dp.size() - 1];
}

int main(){
    return 0;
}