#include <iostream>
#include <vector>
using namespace std;

int arraySign(vector<int>& nums) {
    int minus = 0;

    for (auto & it: nums) {
        if (it == 0) {
            return 0;
        } else if (it < 0) {
            minus++;
        }
    }        

    if (minus%2) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    return 0;
}