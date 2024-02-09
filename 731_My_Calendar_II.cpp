#include <iostream>
#include <vector>
#include <map>
using namespace std;

class MyCalendarTwo {
public:
    map <int, int> local;
    map <int, int> aggregate;

    MyCalendarTwo() {
        ;
    }
    
    bool book(int start, int end) {
        auto it = aggregate.lower_bound(-(start - 1));

        int prev = 0;
        if (it != aggregate.end()) {
            prev = (*it).second;
        }

        int keep = prev;

        local[start]++;
        local[end]--;

        auto hold = local.lower_bound(start);
        auto keepHold = hold;

        bool ret = true;
        while (hold != local.end() && (*hold).first <= end) {
            prev += (*hold).second;

            if (prev >= 3) {
                ret = false;
                break;
            }

            hold++;
        }

        if (ret) {
            prev = keep;
            hold = keepHold;
            while (hold != local.end() && (*hold).first <= end) {
                prev += (*hold).second;

                aggregate[-(*hold).first] = prev;    

                hold++;
            }   
        } else {
            local[start]--;
            local[end]++;
        }

        return ret;
    }
};

int main() {
    return 0;
}