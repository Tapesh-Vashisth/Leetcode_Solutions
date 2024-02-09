#include <iostream>
#include <vector>
using namespace std;

class LUPrefix {
private:
    vector <bool> store;
    int mx;

public:
    LUPrefix(int n) {
        mx = 0;
        store.resize(n + 1, false);
        store[0] = true;
    }
    
    void upload(int video) {
        store[video] = true;
        while (mx + 1 < store.size() && store[mx + 1]) {
            mx++;
        }
    }
    
    int longest() {
        return mx;
    }
};

int main() {
    return 0;
}