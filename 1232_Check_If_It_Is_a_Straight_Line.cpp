#include <iostream>
#include <vector>
using namespace std;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int prevNum;
    int prevDen;
    for (int i = 1; i < coordinates.size(); i++) {
        int num = coordinates[i][1] - coordinates[0][1];
        int den = coordinates[i][0] - coordinates[0][0];

        int div = gcd(abs(num), abs(den));

        int simNum = num/div;
        int simDen = den/div;

        if (i == 1) {
            prevNum = simNum;
            prevDen = simDen;
        } else {
            if (prevNum * prevDen != simNum * simDen) {
                return false;
            }
        }
    }        

    return true;
}

int main() {
    return 0;
}