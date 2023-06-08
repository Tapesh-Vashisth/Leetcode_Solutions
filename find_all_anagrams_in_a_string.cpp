#include <iostream>
#include <vector>
using namespace std;

int counter(vector <int> & store) {
    int nonzeroes = 0;
    for (auto i: store) {
        if (i != 0) {
            nonzeroes++;
        }
    }

    return nonzeroes;
}

vector<int> findAnagrams(string s, string p) {
    vector <int> ret;
    if (p.size() > s.size()) {
        return ret;
    }

    vector <int> hashed(26, 0);

    int ones = 0;
    for (int i = 0; i < p.size(); i++) {
        hashed[p[i] - 'a']++;
    }

    for (int i = 0; i < hashed.size(); i++) {
        cout << hashed[i] << " ";
    }
    cout << endl;

    for (int i = s.size() - 1; i >= s.size() - p.size(); i--) {
        hashed[s[i] - 'a']--;
    }

    if (counter(hashed) == 0) {
        ret.push_back(s.size() - p.size());
    }

    for (int i = s.size() - p.size() - 1; i >= 0; i--) {
        hashed[s[i] - 'a']++;
        hashed[s[i + p.size()] - 'a']--;

        int decider = counter(hashed);

        if (decider == 0) {
            ret.push_back(i);
        }
    }

    return ret;
}

int main() {
    return 0;
}