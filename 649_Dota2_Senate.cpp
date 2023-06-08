#include <iostream>
using namespace std;

string predictPartyVictory(string senate) {
    int rs = 0;
    int ds = 0;
    for (auto it: senate) {
        if (it == 'R') {
            rs++;
        } else {
            ds++;
        }
    }

    int skiprs = 0;
    int skipds = 0;

    int pointer = 0;

    while (rs > 0 && ds > 0) {
        if (senate[pointer] == 'C') {
            ;
        } else {
            if (senate[pointer] == 'R') {
                if (skiprs) {
                    senate[pointer] = 'C';
                    skiprs--;
                } else if (ds) {
                    ds--;
                    skipds++;
                }
            } else {
                if (skipds) {
                    senate[pointer] = 'C';
                    skipds--;
                } else if (rs) {
                    rs--;
                    skiprs++;
                }
            }
        }

        pointer = (pointer + 1) % senate.size();
    }

    if (rs > ds) {
        return "Radiant";
    } else {
        return "Dire";
    }
}

int main() {
    return 0;
}