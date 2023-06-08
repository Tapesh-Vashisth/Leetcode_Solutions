#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices){
    vector <int> deals;
    int mn = prices[0];
    for (int i = 0; i < prices.size(); i++){
        deals.push_back(prices[i] - mn);

        if (prices[i] < mn){
            mn = prices[i];
        }
    }

    return *min(prices.begin(), prices.end());
}

int main(){
    return 0;
}