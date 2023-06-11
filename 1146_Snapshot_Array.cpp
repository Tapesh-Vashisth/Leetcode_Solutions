#include <iostream>
#include <vector>
using namespace std;

class SnapshotArray {
public:
    int snaps;
    vector <vector <pair <int, int>>> store;

    SnapshotArray(int length) {
        store = vector <vector <pair <int, int>>> (length, vector <pair <int, int>> (1, {0, 0})); 
        snaps = 0;  
    }
    
    void set(int index, int val) {
        if (snaps > store[index][store[index].size() - 1].first) {
            store[index].push_back({snaps, val});
        } else {
            store[index][store[index].size() - 1].second = val;
        }
    }
    
    int snap() {
        snaps++;
        return snaps - 1;
    }
    
    int get(int index, int snap_id) {
        int pos = lower_bound(store[index].begin(), store[index].end(), make_pair(snap_id, 0)) - store[index].begin();

        if (pos == store[index].size()) {
            return store[index][pos - 1].second;
        } else if (store[index][pos].first == snap_id) {
            return store[index][pos].second;
        } else {
            return store[index][pos - 1].second;
        }
    }
};

int main() {
    return 0;
}