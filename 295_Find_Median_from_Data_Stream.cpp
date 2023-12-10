#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue <int> p1;
    priority_queue <int, vector<int>, greater<int>> p2;

    MedianFinder() {
        ;    
    }
    
    void addNum(int num) {
        int first = p1.top();
        int second = p2.top();

        p1.push(num);

        while (p1.size() - p2.size() > 1) {
            p2.push(p1.top());
            p1.pop();
        }
    }
    
    double findMedian() {
        double ans = 0;
        if ((p1.size() + p2.size()) % 2 == 0) {
            ans = (p1.top() + p2.top())/2.0;
        } else {
            ans = p1.top();
        }

        return ans;
    }
};

int main() {
    return 0;
}