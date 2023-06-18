#include <iostream>
using namespace std;

int distanceTraveled(int mainTank, int additionalTank) {
    int ans = 0;
    while (mainTank > 0) {
        int travelled = min(5, mainTank);
        ans += (travelled * 10);
        mainTank -= travelled;

        if (travelled == 5 && additionalTank > 0) {
            mainTank++;
            additionalTank--;
        }
    }        

    return ans;
}

int main() {
    return 0;
}