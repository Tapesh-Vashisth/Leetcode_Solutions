#include <iostream>
#include <vector>
using namespace std;

int minFlips(int a, int b, int c) {
    vector <int> target(32, 0);
    vector <int> as(32, 0);
    vector <int> bs(32, 0);

    int counter = 0;
    while (c) {
        if (c & 1) {
            target[counter]++;
        }
        counter++;
        c = c >> 1;
    }

    counter = 0;
    while (a) {
        if (a & 1) {
            as[counter]++;
        }
        counter++;
        a = a >> 1;
    }

    counter = 0;
    while (b) {
        if (b & 1) {
            bs[counter]++;
        }
        counter++;
        b = b >> 1;
    }

    int ans = 0;

    for (int i = 0; i < 32; i++) {
        if (target[i] == 1 && (as[i] == 0 && bs[i] == 0)) {
            ans += 1;
        } else if (target[i] == 0 && (as[i] == 1 || bs[i] == 1)) {
            ans += (as[i] == 1) + (bs[i] == 1);
        }
    }

    return ans;
}

int main() {
    return 0;
}