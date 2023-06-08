#include <iostream>
#include <set>
using namespace std;

int flipLights(int n, int presses) {
    int totalOptions = 2 * 2 * 2 * 2;
    set <string> s;

    for (int i = 0; i < totalOptions; i++) {
        int hold = i;
        int decider = i;

        int deciderCount = 0;
        while (decider) {
            if (decider & 1) {
                deciderCount++;
            }

            decider = decider >> 1;
        }

        if (deciderCount <= presses) {
            string str;
            for (int j = 0; j < n; j++) {
                str.push_back('1');
            }    

            int counter = 0;
            while (hold) {
                if (hold & 1) {
                    if (counter == 0) {
                        for (int j = 0; j < n; j += 1) {
                            str[j] = str[j] == '1' ? '0' : '1';
                        }
                    } else if (counter == 1) {
                        for (int j = 0; j < n; j += 2) {
                            str[j] = str[j] == '1' ? '0' : '1';
                        }
                    } else if (counter == 2) {
                        for (int j = 1; j < n; j += 2) {
                            str[j] = str[j] == '1' ? '0' : '1';
                        }
                    } else if (counter == 3) {
                        for (int j = 0; j < n; j += 3) {
                            str[j] = str[j] == '1' ? '0' : '1';
                        }
                    }
                }
                hold = hold >> 1;
                counter++;
            }

            s.insert(str);
        }

    }

    return s.size();
}

int main() {
    return 0;
}