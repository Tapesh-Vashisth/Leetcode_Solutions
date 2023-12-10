#include <iostream>
#include <vector>
using namespace std;

bool winnerOfGame(string colors) {
    int bob = 0;
    int alice = 0;
    int temp = 1;
    for (int i = 1; i < colors.size(); i++) {
        if (colors[i] != colors[i - 1]) {
            if (colors[i - 1] == 'A') {
                alice += max(0, temp - 2);
            } else {
                bob += max(0, temp - 2);
            }

            temp = 1;
        } else {
            temp++;
        }
    }    

    if (colors[colors.size() - 1] == 'B') {
        bob += max(0, temp - 2);
    } else {
        alice += max(0, temp - 2);
    } 

    return alice > bob;
}

int main() {
    return 0;
}