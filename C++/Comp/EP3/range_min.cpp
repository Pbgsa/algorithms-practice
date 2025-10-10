#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

struct SegmentTree {
    int n;
    vector<int> seg;

    SegmentTree(int n) {
        this->n = n;
        seg.assign(4 * n, INF);
    }

    void build(vector<int> &arr, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * idx, l, mid);
        build(arr, 2 * idx + 1, mid + 1, r);
        seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);
        seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return INF;
        if (ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) / 2;
        return min(query(2 * idx, l, mid, ql, qr),
                   query(2 * idx + 1, mid + 1, r, ql, qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    SegmentTree st(n);
    st.build(arr, 1, 1, n);

    while (q--) {
        int q_type;
        cin >> q_type;
        if (q_type == 1) {
            int k, u;
            cin >> k >> u;
            st.update(1, 1, n, k, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << st.query(1, 1, n, a, b) << '\n';
        }
    }
    return 0;
}
