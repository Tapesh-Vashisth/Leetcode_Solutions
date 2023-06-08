#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long hold = 5;
    vector <long long> store = {0, 5};
    long long counter = 1;
    long long x = 10;
    while (hold < 1000000010) {
        store.push_back(hold + x);
        hold = hold + x;
        x = x*2;
        counter++;
    }

    int pos = lower_bound(store.begin(), store.end(), n) - store.begin();
    long long decider = n - store[pos - 1];
    long long mainDecider = ceil(decider/(pow(2, pos - 1)));

    if (mainDecider == 1) {
        cout << "Sheldon" << endl;
    } else if(mainDecider == 2) {
        cout << "Leonard" << endl;
    } else if(mainDecider == 3) {
        cout << "Penny" << endl;
    } else if(mainDecider == 4) {
        cout << "Rajesh" << endl;
    } else if(mainDecider == 5) {
        cout << "Howard" << endl;
    } 
    return 0;
}