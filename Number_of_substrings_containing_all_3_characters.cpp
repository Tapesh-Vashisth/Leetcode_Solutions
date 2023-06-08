#include <iostream>
#include <vector>
using namespace std;

int numberOfSubstrings(string s) {
    int low = 0;
    int high = 0;
    vector <int> hash(3, 0);
    hash[s[0] - 'a']++;
    int ans = 0;
    while (low <= high) {
        if (hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
            ans += s.size() - high;
            hash[s[low] - 'a']--;
            low++;
        } else {
            if (high < s.size() - 1) {
                high++;
                hash[s[high] - 'a']++;
            } else {
                hash[s[low] - 'a']--;
                low++;
            }
        }
    }

    return ans;
}

int main() {
    cout << numberOfSubstrings("abcabc") << endl;
    return 0;
}