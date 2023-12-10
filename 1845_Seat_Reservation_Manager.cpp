#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class SeatManager {
public:
    priority_queue <int, vector<int>, greater<int>> store;

    SeatManager(int n) {
        for (int i = 0; i < n; i++) {
            store.push(i + 1);
        }
    }
    
    int reserve() {
        int hold = store.top();
        store.pop();

        return hold;
    }
    
    void unreserve(int seatNumber) {
        store.push(seatNumber);
    }
};

int main() {
    
    return 0;
}