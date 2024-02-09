#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


// summation
struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this->n = _n;
        st.resize(2 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        // leaf node base case
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, node + 2 * (mid - start + 1), v);

        st[node] = st[node + 1] + st[node + 2 * (mid - start + 1)];
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, node + 1);
        int q2 = query(mid + 1, ending, l, r, node + 2 * (mid - start + 1));

        return q1 + q2;
    }

    void update(int start, int ending, int node, int index, int value) {
        // base case
        if (start == ending) {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) {
            // left subtree
            update(start, mid, node + 1, index, value);
        }
        else {
            // right
            update(mid + 1, ending, node + 2 * (mid - start + 1), index, value);
        }

        st[node] = st[node + 1] + st[node + 2 * (mid - start + 1)];

        return;
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};

int main() {
    vector <int> arr = {1, 2, 3, 4, 5};
    segmenttree st;
    st.init(arr.size());
    st.build(arr);

    cout << st.query(0, 2) << endl;
    st.update(1, 5);
    cout << st.query(0, 2) << endl;
    

    return 0;
}