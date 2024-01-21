#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

class RandomizedSet {
public:
    vector <int> store;
    map <int, int> mapped;
    int sz = 0;

    RandomizedSet() {
        sz = 0;
    }
    
    bool insert(int val) {
        bool ret = false;
        if (mapped[val] != 0) {
            ret = false;
        } else {
            if (sz == store.size()) {
                store.push_back(val);
                sz++;
                mapped[val] = sz;
            } else {
                store[sz] = val;
                sz++;
                mapped[val] = sz;
            }

            ret = true;
        }

        return ret;
    }
    
    bool remove(int val) {
        bool ret = false;
        if (mapped[val] != 0) {
            int pos = mapped[val] - 1;

            // exchange 
            store[pos] = store[sz - 1];
            mapped[store[pos]] = pos + 1;
            sz--;

            mapped[val] = 0;

            ret = true;
        } else {
            ret = false;
        }

        return ret;
    }
    
    int getRandom() {
        int randpos = (rand() % sz);

        return store[randpos];
    }
};

int main() {
    return 0;
}