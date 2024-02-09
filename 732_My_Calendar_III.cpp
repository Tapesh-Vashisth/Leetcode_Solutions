#include <iostream>
#include <vector>
#include <map>
using namespace std;

class MyCalendarThree {
public:
    map <int, int> local;
    map <int, int> aggregate;

    int mx = 0;
    MyCalendarThree() {
        mx = 0;
    }
    
    int book(int start, int end) {
        auto it = aggregate.lower_bound(-(start - 1));

        int prev = 0;
        if (it != aggregate.end()) {
            prev = (*it).second;
        }

        local[start]++;
        local[end]--;

        auto hold = local.lower_bound(start);

        int ret = 1;
        while (hold != local.end() && (*hold).first <= end) {
            prev += (*hold).second;

            ret = max(ret, prev);
            aggregate[-(*hold).first] = prev;    

            hold++;
        }

        mx = max(ret, mx);

        return mx;
    }
};

int main() {
    return 0;
}