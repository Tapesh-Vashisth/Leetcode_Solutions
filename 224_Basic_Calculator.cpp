#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int parseInt(string & s, int & start) {
    int num = 0;
    while (start < s.size() && s[start] >= '0' && s[start] <= '9') {
        num = (num * 10) + (s[start] - '0');
        start++;
    }

    return num;
}

int helper(string & s, int low, int high, vector <int> & hash) {
    int index = low;
    int ret = 0;
    while (index <= high) {
        if (s[index] == '+') {
            index++;
            while (s[index] == ' ') {
                index++;
            }

            if (s[index] == '(') {
                ret += helper(s, index + 1, hash[index] - 1, hash);
                index = hash[index] + 1;
            } else {
                int hold = parseInt(s, index);
                ret += hold;
            }
        } else if (s[index] == '-') {
            index++;
            while (s[index] == ' ') {
                index++;
            }

            if (s[index] == '(') {
                ret -= helper(s, index + 1, hash[index] - 1, hash);
                index = hash[index] + 1;
            } else {
                int hold = parseInt(s, index);
                ret -= hold;
            }
        } else if (s[index] == '(') {
            ret += helper(s, index + 1, hash[index] - 1, hash);
            index = hash[index] + 1;
        } else if (s[index] == ' ') {
            index++;
        } else {
            int hold = parseInt(s, index);
            ret += hold;
        }
    }

    return ret;
}

int calculate(string s) {
    stack <int> store;
    vector <int> hash(s.size(), -1);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            store.push(i);
        } else if (s[i] == ')') {
            int hold = store.top();
            hash[hold] = i;
            store.pop();
        }
    }

    int ans = 0;
    
    ans += helper(s, 0, s.size() - 1, hash);

    return ans;
}

int main() {
    return 0;
}