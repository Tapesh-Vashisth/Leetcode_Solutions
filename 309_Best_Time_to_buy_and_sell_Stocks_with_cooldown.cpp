#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> memory;

int maxProfitHelper(vector <int>& prices, int day, int mode){
    if (day == prices.size()){
        if (mode == 0 || mode == 2){
            return 0;
        }else{
            return -1;
        }
    }

    if (memory[day][mode] != -1){
        return memory[day][mode];
    }

    if (mode == 0){
        // buy or not
        int bought = maxProfitHelper(prices, day + 1, 1);
        int notBought = maxProfitHelper(prices, day + 1, 0);
        memory[day][mode] = max(bought - prices[day], notBought);
        return max(bought - prices[day], notBought);
    }else if(mode == 1){
        // sell or not
        int sold = maxProfitHelper(prices, day + 1, 2);
        int notSold = maxProfitHelper(prices, day + 1, 1);

        memory[day][mode] = max(sold + prices[day], notSold);
        return max(sold + prices[day], notSold);
    }else{
        // cooldown 
        int next = maxProfitHelper(prices, day + 1, 0);
        memory[day][mode] = next;    
        return next;
    }
}

int maxProfit(vector<int>& prices) {
    memory = vector<vector<int>>(prices.size(), vector<int>(3, -1));
    int ans = maxProfitHelper(prices, 0, 0);
    return ans;
}

int main(){
    
    return 0;
}