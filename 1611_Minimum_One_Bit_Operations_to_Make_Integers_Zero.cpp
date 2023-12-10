#include <iostream>
#include <vector>
using namespace std;

int minimumOneBitOperations(int n) {
    int ans = 0;

    int offset = 31;
    int hold = INT32_MAX;
    int counter = 0;

    while (offset) {
        if (((1 << (offset - 1)) & n)) {
            if (counter % 2 == 0) {
                ans += hold;
            } else {
                ans -= hold;
            }

            counter++;  
        }

        hold = hold >> 1;
        offset--;
    }

    return ans;
}

int main() {
    minimumOneBitOperations(5);
    return 0;
}