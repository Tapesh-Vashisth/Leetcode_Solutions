#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

string destCity(vector<vector<string>>& paths) {
    set <string> keep;
    map <string, int> store;

    for (auto & it: paths) {
        keep.insert(it[0]);
        keep.insert(it[1]);
        store[it[0]]++;
    }

    for (auto & it: keep) {
        if (store[it] == 0) {
            return it;
        }
    }

    return "";
}

int main() {
    return 0;
}