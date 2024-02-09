#include <iostream>
#include <vector>
using namespace std;


int check(vector <string> & arr, vector <bool> & taken) {
    vector <bool> hash(26, false);
    int ret = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (taken[i] == true) {
            for (auto it: arr[i]) {
                if (hash[it - 'a']) {
                    return 0;
                }

                hash[it - 'a'] = true;
                ret++;
            }
        }
    }

    return ret;
}


int helper(int current, vector <string> & arr, vector <bool> & taken) {
    if (current >= arr.size()) {
        return check(arr, taken);
    }

    int ret = 0;

    // take 
    taken[current] = true;
    ret = max(ret, helper(current + 1, arr, taken));

    // not take 
    taken[current] = false;
    ret = max(ret, helper(current + 1, arr, taken));

    return ret;
}

int maxLength(vector<string>& arr) {
    vector <bool> taken(arr.size(), false);
    return helper(0, arr, taken);
}

int main() {
    return 0;
}