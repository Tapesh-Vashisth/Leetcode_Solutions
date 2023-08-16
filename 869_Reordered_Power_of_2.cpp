#include <iostream>
#include <vector>
using namespace std;


bool isPowerOf2(int n) {
    if ((n & (n - 1)) == 0){
        return 1;
    }else{
        return 0;
    }
}

bool helper(string & num, int place, int hold, vector <bool> & used) {
    if (place == num.size()) {
        return isPowerOf2(hold);
    }

    for (int i = 0; i < num.size(); i++) {
        if ((place == 0 && num[i] != '0') || place != 0) {
            if (used[i]) {
                used[i] = false;
                bool check = helper(num, place + 1, (hold * 10) + (num[i] - '0'), used);
                if (check) {
                    return true;
                }
                used[i] = true;
            }        
        }
    }

    return false;
}

bool reorderedPowerOf2(int n) {
    string num = to_string(n);
    vector <bool> used(num.size(), true);
    return helper(num, 0, 0, used);
}

int main() {
    return 0;
}