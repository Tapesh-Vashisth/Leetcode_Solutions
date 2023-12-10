#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCoins(vector<int>& piles) {
    int ans = 0;
    sort(piles.begin(), piles.end());

    int index = piles.size() - 2;
    int counter = 0;

    while (counter < piles.size() / 3) {
        ans += piles[index];
        index -= 2;
        counter++;
    }

    return ans;
}

int main() {
    return 0;
}