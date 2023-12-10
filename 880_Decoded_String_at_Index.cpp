#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long parseInt(string & s, int & start) {
    long long ret = 1;
    while (start < s.size() && s[start] >= '2' && s[start] <= '9') {
        ret = ret * (s[start] - '0');
        start++;
    }

    return ret;
} 

string decodeAtIndex(string s, int k) {
    long long index = 0;

    vector <long long> positions = {-1};
    vector <long long> lengths = {-1};
    vector <int> inString = {0};

    k--;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '2' && s[i] <= '9') {
            long long hold = parseInt(s, i);
            lengths.push_back(index);
            index = index * hold;
            positions.push_back(index - 1);
            inString.push_back(i);
            i--;
        } else {
            index++;
        }
    }   

    if (!(s[s.size() - 1] >= '2' && s[s.size() - 1] <= '9')) {
        lengths.push_back(index);
        positions.push_back(index - 1);
        inString.push_back(s.size());
    }

    string ans;

    while (true) {
        int keep = lower_bound(positions.begin(), positions.end(), k) - positions.begin();

        k = k % lengths[keep];

        if (k > positions[keep - 1]) {
            ans.push_back(s[inString[keep - 1] + (k - positions[keep - 1] - 1)]);
            break;
        } else {
            ;
        }
    }

    return ans;
}

int main() {
    return 0;
}