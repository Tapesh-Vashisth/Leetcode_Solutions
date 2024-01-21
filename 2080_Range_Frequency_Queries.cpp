#include <iostream>
#include <vector>
#include <map>
using namespace std;


struct segmenttree {
    int n;
    vector<map <int, int>> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        // leaf node base case
        if (start == ending) {
            st[node][v[start]] = 1;
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        for (auto it: st[node * 2 + 1]) {
            st[node][it.first] += it.second;
        }

        for (auto it: st[node * 2 + 2]) {
            st[node][it.first] += it.second;
        }
    }

    int query(int start, int ending, int l, int r, int node, int value) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node][value];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1, value);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2, value);

        return q1 + q2;
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r, int v) {
        return query(0, n - 1, l, r, 0, v);
    }
};


class RangeFreqQuery {
public:
    segmenttree st;

    RangeFreqQuery(vector<int>& arr) {
        st.init(arr.size());
        st.build(arr);
    }
    
    int query(int left, int right, int value) {
        return st.query(left, right, value);
    }
};

int main() {
    return 0;
}