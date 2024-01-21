#include <iostream>
#include <vector>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;


class MyCalendar {
public:
    indexed_set starts;
    indexed_set ends;

    MyCalendar() {
        ;
    }
    
    bool book(int start, int end) {
        bool ret = true;
        if (starts.order_of_key(start + 1) > ends.order_of_key(start + 1)) {
            ret = false;
        } 

        if (starts.order_of_key(end) > ends.order_of_key(end)) {
            ret = false;
        }

        if (starts.order_of_key(end) > starts.order_of_key(start + 1)) {
            ret = false;
        }

        if (ret) {
            starts.insert(start);
            ends.insert(end);
        }

        return ret;
    }
};


int main() {
    return 0;
}