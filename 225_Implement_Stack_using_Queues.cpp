#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MyStack {
public:
    queue <int> store;

    MyStack() {
        ;
    }
    
    void push(int x) {
        store.push(x);
    }
    
    int pop() {
        int size = store.size();
        int counter = 0;
        while (counter < size - 1) {
            int hold = store.front();
            store.pop();
            store.push(hold);
            counter++;
        }

        int del = store.front();
        store.pop();
        return del;
    }
    
    int top() {
        int size = store.size();
        int counter = 0;
        while (counter < size - 1) {
            int hold = store.front();
            store.pop();
            store.push(hold);
            counter++;
        }

        int ret = store.front(); 
        store.pop();
        store.push(ret);  
        return ret;
    }
    
    bool empty() {
        return (store.size() == 0);
    }
};

int main() {
    return 0;
}