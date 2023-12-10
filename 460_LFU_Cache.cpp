#include <iostream>
#include <vector>
#include <set>
using namespace std;

class LFUCache {
public:
    set <vector <int>> pq;
    vector <vector <int>> mapping;
    int maxCap = 0;
    int recent = 0;

    LFUCache(int capacity) {
        maxCap = capacity;
        recent = 0;
        mapping.resize(1e5 + 1, {-1, -1, -1});
    }
    
    int get(int key) {
        if (mapping[key][2] != -1) {
            pq.erase({mapping[key][0], mapping[key][1], key});
            pq.insert({mapping[key][0] + 1, recent++, key});
            mapping[key] = {mapping[key][0] + 1, recent - 1, mapping[key][2]};
        }

        return mapping[key][2];
    }
    
    void put(int key, int value) {
        if (mapping[key][2] == -1) {
            if (pq.size() >= maxCap) {
                int hold = (*pq.begin())[2];
                mapping[hold][2] = -1;
                pq.erase(pq.begin());
            }

            pq.insert({1, recent++, key});
            mapping[key] = {1, recent - 1, value};
        } else {
            pq.erase({mapping[key][0], mapping[key][1], key});
            pq.insert({mapping[key][0] + 1, recent++, key});
            mapping[key] = {mapping[key][0] + 1, recent - 1, value};
        }
    }
};

int main() {
    return 0;
}