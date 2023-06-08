#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


bool check(vector <int>& piles, int rate, int h){
    int total = 0;
    for (int i = 0; i < piles.size(); i++){
        total += ceil((piles[i]* 1.0)/rate);
    }

    return total <= h? true: false;
}

int minEatingSpeed(vector<int>& piles, int h){
    sort(piles.begin(), piles.end());

    long long low = piles[0];
    long long high = piles[piles.size() - 1];
    while (low < high){
        long long mid = low + (high - low)/2;

        if (check(piles, mid, h)){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return low;
}

int main(){

    return 0;
}