#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int bitsToNum(string & s) {
    int ret = 0;
    int mul = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            ret += mul;
        }

        mul = mul * 2;
    }

    return ret;
}

string numstoBits(int n, int size) {
    string ret = "";
    for (int i = 0; i < size; i++) {
        if (n & (1 << i)) {
            ret.push_back('1');
        } else {
            ret.push_back('0');
        }
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

string findDifferentBinaryString(vector<string>& nums) {
    map <int, bool> store;
    for (auto it: nums) {
        int hold = bitsToNum(it);
        cout << hold << endl;
        store[hold] = true;
    }        

    int index = 0;
    while (store[index]) {
        index++;
    }

    return numstoBits(index, nums.size());
}

int main() {
    return 0;
}