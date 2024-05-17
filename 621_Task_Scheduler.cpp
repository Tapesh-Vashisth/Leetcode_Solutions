#include <iostream>
#include <vector>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    int timer = 0;
    vector <int> lastUsed(26, -200);

    int hold = 0;

    vector <int> counter(26, 0);
    for (auto it: tasks) {
        counter[it - 'A']++;
    } 

    while (hold < tasks.size()) {
        int mx = -1;
        int index = -1;

        for (int i = 0; i < 26; i++) {
            if (lastUsed[i] < timer - n) {
                if (counter[i] > 0) {
                    if (counter[i] > mx) {
                        index = i;
                        mx = counter[i];
                    }
                }
            }
        }

        if (index != -1) {
            lastUsed[index] = timer;
            counter[index]--;
            hold++;
        }

        timer++;
    }        


    return timer;
}

int main() {
    return 0;
}