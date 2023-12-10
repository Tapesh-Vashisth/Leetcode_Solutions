#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// summation
struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v) {
    // leaf node base case
    if (start == ending) {
        st[node] = v[start];
        return;
    }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return INT32_MIN;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return max(q1, q2);
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
            update(start, mid, 2 * node + 1, index, value);
        }
        else {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);

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

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());

    segmenttree st;
    st.init(1e5 + 5);

    vector <pair <int, int>> store;

    int ans = 0;

    for (int i = 0; i < envelopes.size(); i++) {
        bool decider = false;
        if (i > 0) {
            decider = envelopes[i][0] > envelopes[i - 1][0];
        }

        if (decider) {
            for (auto it: store) {
                st.update(it.first, it.second);
            }

            store.clear();
        }

        int hold = st.query(0, envelopes[i][1] - 1) + 1;
        ans = max(ans, hold);
        store.push_back({envelopes[i][1], hold});
    }

    return ans;
}

int main() {
    return 0;
}