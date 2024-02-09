#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack <int> first;
    stack <int> second;

    MyQueue() {
        ;
    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        int ret = -1;   
        if (second.size() == 0) {
            while (!first.empty()) {
                int hold = first.top();
                first.pop();
                second.push(hold);
            }

            ret = second.top();
            second.pop();
        } else {
            ret = second.top();
            second.pop();
        }

        return ret;
    }
    
    int peek() {
        int ret = -1;
        if (second.size() == 0) {
            while (!first.empty()) {
                int hold = first.top();
                first.pop();
                second.push(hold);
            }

            ret = second.top();
        } else {
            ret = second.top();
        }

        return ret;
    }
    
    bool empty() {
        return !(first.size() || second.size());
    }
};

int main() {
    return 0;
}