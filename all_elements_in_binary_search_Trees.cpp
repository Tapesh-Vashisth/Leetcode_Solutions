#include <iostream>
#include <vector>
using namespace std;

vector <int> mergeSorted(vector <int> & first, vector <int> & second) {
    vector <int> ret;
    int fir = 0;
    int sec = 0;
    while (fir < first.size() && sec < second.size()) {
        if (first[fir] < second[sec]) {
            ret.push_back(first[fir]);
            fir++;
        } else {
            ret.push_back(second[sec]);
            sec++;
        }
    }

    while (fir < first.size()) {
        ret.push_back(first[fir]);
        fir++;
    }

    while (sec < second.size()) {
        ret.push_back(second[sec]);
        sec++;
    }

    return ret;
}

int main() {
    return 0;
}