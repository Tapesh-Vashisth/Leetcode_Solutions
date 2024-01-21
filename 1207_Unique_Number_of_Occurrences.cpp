#include <iostream>
#include <vector>
#include <set>
using namespace std;


bool uniqueOccurrences(vector<int>& arr) {
    vector <int> hash(2e3 + 5, 0);
    for (auto it: arr) {
        hash[it + 1000]++;
    }

    set <int> store;
    int counter = 0;
    for (auto it: hash) {
        if (it > 0) {
            counter++;
            store.insert(it);
        }
    }

    return counter == store.size();
}

int main() {
    return 0;
}