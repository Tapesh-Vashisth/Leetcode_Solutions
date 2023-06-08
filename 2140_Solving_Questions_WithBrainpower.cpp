#include <iostream>
#include <vector>
using namespace std;

long long mostPoints(vector<vector<int>>& questions) {
    long long ans = 0;
    vector <long long> store(questions.size(), 0);
    long long holdmax = 0;
    for (int i = 0; i < questions.size(); i++) {
        long long hold = max(store[i] + questions[i][0], holdmax + questions[i][0]);
        
        holdmax = max(holdmax, store[i]);

        ans = max(ans, hold);

        if (i + questions[i][1] + 1 < questions.size()) {
            store[i + questions[i][1] + 1] = max(store[i + questions[i][1] + 1], hold);
        }
    }

    return ans;
}

int main() {
    return 0;
}