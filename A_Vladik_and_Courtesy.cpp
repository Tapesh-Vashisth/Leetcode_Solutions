#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long first = floor(sqrt(a));

    double d = (sqrt(1 + 4*b) - 1)/2;
    long long second = floor(d);

    if (first <= second) {
        cout << "Vladik" << endl;
    } else {
        cout << "Valera" << endl;
    }
    return 0;
}