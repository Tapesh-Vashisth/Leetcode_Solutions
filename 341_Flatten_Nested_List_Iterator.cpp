#include <iostream>
#include <vector>
using namespace std;

class NestedIterator {
public:
    int current;
    vector <int> store;

    NestedIterator(vector<NestedInteger> &nestedList) {
        current = 0;
        helper(nestedList);
        cout << "hm" << endl;
    }

    void helper(vector <NestedInteger> & nestedList) {
        for (auto & it: nestedList) {
            if (it.isInteger()) {
                store.push_back(it.getInteger());
            } else {
                helper(it.getList());
            }
        }
    }
    
    int next() {
        return store[current++];
    }
    
    bool hasNext() {
        if (current < store.size()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    return 0;
}