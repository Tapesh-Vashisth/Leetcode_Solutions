#include <iostream>
#include <vector>
#include <set>
using namespace std;

class LRUCache {
public:
    vector <int> freqRanker;
    set <pair <int, int>> store;
    vector <int> cache;
    int capacity;
    int currently;
    int mx;

    LRUCache(int capacity) {
        freqRanker = vector <int> (10005, -1);
        cache = vector <int> (10005, -1);
        this->capacity = capacity;
        this->currently = 0;
        this->mx = 0;
    }
    
    int get(int key) {
        if (freqRanker[key] == -1) {
            ;
        } else {
            store.erase({freqRanker[key], key});
            mx++;
            store.insert({mx, key});
            freqRanker[key] = mx;
        }

        return cache[key];
    }
    
    void put(int key, int value) {
        if (currently == capacity) {
            if (freqRanker[key] == -1) {
                cache[(*store.begin()).second] = -1;
                freqRanker[(*store.begin()).second] = -1;
                store.erase(store.begin());
                mx++;
                store.insert({mx, key});
                freqRanker[key] = mx;
                cache[key] = value;
            } else {
                store.erase({freqRanker[key], key});
                mx++;
                store.insert({mx, key});
                freqRanker[key] = mx;
                cache[key] = value;
            }
        } else {
            if (freqRanker[key] == -1) {
                mx++;
                store.insert({mx, key});
                freqRanker[key] = mx;
                cache[key] = value;
                currently++;
            } else {
                store.erase({freqRanker[key], key});
                mx++;
                store.insert({mx, key});
                freqRanker[key] = mx; 
                cache[key] = value;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    return 0;
}