#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// max
struct segmenttree {
    int n;
    vector<pair <int, int>> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, {INT32_MIN, -1});
    }

    void build(int start, int ending, int node, vector<int> &v) {
        // leaf node base case
        if (start == ending) {
            st[node] = {v[start], start};
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
    }

    pair <int, int> query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return {INT32_MIN, -1};
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        pair <int, int> q1 = query(start, mid, l, r, 2 * node + 1);
        pair <int, int> q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return max(q1, q2);
    }

    void update(int start, int ending, int node, int index, int value) {
        // base case
        if (start == ending) {
            st[node] = {value, index};
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

    pair <int, int> query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    segmenttree st; 

    vector <pair <int, int>> store;
    for (int i = 0; i < profits.size(); i++) {
        store.push_back({capital[i], profits[i]});
    }

    sort(store.begin(), store.end());

    vector <int> seginit;
    for (auto & it: store) {
        seginit.push_back(it.second);
    }

    st.init(profits.size());
    st.build(seginit);

    int index = 0;
    int taken = 0;
    while (index < profits.size() && taken < k) {
        if (w <= store[index].first) {
            index++;
        } else {
            pair <int, int> hold = st.query(0, index - 1);
            w += hold.first;
            st.update(hold.second, -1);
            taken++;
        }
    }

    return w;
}

int main() {
    return 0;
}