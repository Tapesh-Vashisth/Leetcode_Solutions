#include <iostream>
#include <vector>
using namespace std;

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    return (t >= max(abs(sx - fx), abs(sy - fy)) && (!(t == 1 && sx == fx && sy == fy)));        
}

int main() {
    return 0;
}