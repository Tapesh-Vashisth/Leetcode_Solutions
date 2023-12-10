#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
public:
    vector <int> mapped;
    MyHashMap() {
        mapped.resize(1e6 + 5, -1);
    }
    
    void put(int key, int value) {
        mapped[key] = value;
    }
    
    int get(int key) {
        return mapped[key];
    }
    
    void remove(int key) {
        mapped[key] = -1;
    }
};

int main() {
    return 0;
}