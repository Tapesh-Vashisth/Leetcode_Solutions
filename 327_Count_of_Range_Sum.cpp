#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int countRangeSum(vector<int>& nums, int lower, int upper) {
    indexed_set store1;
    indexed_set store2;

    long long sm = 0;
    store1.insert(sm);
    store2.insert(-sm);

    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        sm += nums[i];
        
        ans += (store2.size() - store2.order_of_key(-(sm - lower))) - store1.order_of_key(sm - upper);
        store1.insert(sm);
        store2.insert(-sm);
    }


    return ans;
}

int main() {
    return 0;
}