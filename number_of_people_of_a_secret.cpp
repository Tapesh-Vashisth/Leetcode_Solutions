#include <iostream>
#include <vector>
using namespace std;

int peopleAwareOfSecret(int n, int delay, int forget) {
    vector <int> prefix = {0, 1};
    vector <int> story = {0, 1};
    int current = 2;
    while (current <= n) {
        int upper;
        int lower;
        if (current - delay <= 0) {
            upper = 0;
            lower = 0;
        } else {
            if (current - forget < 0) {
                lower = 0;
                upper = prefix[current - delay];
            } else {
                lower = prefix[current - forget];
                upper = prefix[current - delay];
            }
        }

        story.push_back(upper - lower);
        prefix.push_back(prefix[prefix.size() - 1] + (upper - lower));
    }

    return prefix[n] - prefix[n - forget];
}

int main() {
    return 0;
}