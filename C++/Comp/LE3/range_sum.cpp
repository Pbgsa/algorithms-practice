#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4*n, 0);
        build(1, 0, n-1, arr);
    }

    void build(int idx, int l, int r, vector<int>& arr) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*idx, l, mid, arr);
        build(2*idx+1, mid+1, r, arr);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        return query(2*idx, l, mid, ql, qr) + query(2*idx+1, mid+1, r, ql, qr);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*idx, l, mid, pos, val);
        else update(2*idx+1, mid+1, r, pos, val);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    long long query(int l, int r) { return query(1, 0, n-1, l, r); }
    void update(int pos, int val) { update(1, 0, n-1, pos, val); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    SegmentTree st(v);

    for (int i = 0; i < q; i++) {
        int q_type;
        cin >> q_type;

        if (q_type == 1) {
            int k, u;
            cin >> k >> u;

            st.update(k - 1, u);
        } else if (q_type == 2) {
            int a, b;
            cin >> a >> b;

            cout << st.query(a - 1, b - 1) << "\n";
        }
    }

    return 0;
}
